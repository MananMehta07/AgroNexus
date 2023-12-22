# Importing essential libraries and modules
from turtle import title
from flask import Flask, render_template, request, Markup,redirect
import numpy as np
import pandas as pd
# from utils.disease import disease_dic
from utils.fertilizer import fertilizer_dic
from utils.disease import disease_dic
import requests
# import config
import pickle
import io
import torch
from torchvision import transforms
from PIL import Image
from utils.model import ResNet9

app = Flask(__name__)

@ app.route('/')
def home():
    title = 'AgroNexus'
    return render_template('index.html', title=title)
@ app.route('/fertilizer')
def fertilizer_recommendation():
    title = ' - Fertilizer Suggestion'

    return render_template('fertilizer.html', title=title)

# Loading plant disease classification model

disease_classes = ['Apple___Apple_scab',
                   'Apple___Black_rot',
                   'Apple___Cedar_apple_rust',
                   'Apple___healthy',
                   'Blueberry___healthy',
                   'Cherry_(including_sour)___Powdery_mildew',
                   'Cherry_(including_sour)___healthy',
                   'Corn_(maize)___Cercospora_leaf_spot Gray_leaf_spot',
                   'Corn_(maize)___Common_rust_',
                   'Corn_(maize)___Northern_Leaf_Blight',
                   'Corn_(maize)___healthy',
                   'Grape___Black_rot',
                   'Grape___Esca_(Black_Measles)',
                   'Grape___Leaf_blight_(Isariopsis_Leaf_Spot)',
                   'Grape___healthy',
                   'Orange___Haunglongbing_(Citrus_greening)',
                   'Peach___Bacterial_spot',
                   'Peach___healthy',
                   'Pepper,_bell___Bacterial_spot',
                   'Pepper,_bell___healthy',
                   'Potato___Early_blight',
                   'Potato___Late_blight',
                   'Potato___healthy',
                   'Raspberry___healthy',
                   'Soybean___healthy',
                   'Squash___Powdery_mildew',
                   'Strawberry___Leaf_scorch',
                   'Strawberry___healthy',
                   'Tomato___Bacterial_spot',
                   'Tomato___Early_blight',
                   'Tomato___Late_blight',
                   'Tomato___Leaf_Mold',
                   'Tomato___Septoria_leaf_spot',
                   'Tomato___Spider_mites Two-spotted_spider_mite',
                   'Tomato___Target_Spot',
                   'Tomato___Tomato_Yellow_Leaf_Curl_Virus',
                   'Tomato___Tomato_mosaic_virus',
                   'Tomato___healthy']

disease_model_path = 'models/plant_disease_model.pth'
disease_model = ResNet9(3, len(disease_classes))
disease_model.load_state_dict(torch.load(
    disease_model_path, map_location=torch.device('cpu')))
disease_model.eval()

def predict_image(img, model=disease_model):
    """
    Transforms image to tensor and predicts disease label
    :params: image
    :return: prediction (string)
    """
    transform = transforms.Compose([
        transforms.Resize(256),
        transforms.ToTensor(),
    ])
    image = Image.open(io.BytesIO(img))
    img_t = transform(image)
    img_u = torch.unsqueeze(img_t, 0)

    # Get predictions from model
    yb = model(img_u)
    # Pick index with highest probability
    _, preds = torch.max(yb, dim=1)
    prediction = disease_classes[preds[0].item()]
    # Retrieve the class label
    return prediction



@ app.route('/fertilizer-predict', methods=['GET','POST'])
def fert_recommend():
    title = 'AgroNexus - Fertilizer Suggestion'

    crop_name = str(request.form['cropname'])
    N = int(request.form['nitrogen'])
    P = int(request.form['phosphorous'])
    K = int(request.form['pottasium'])
    # ph = float(request.form['ph'])

    df = pd.read_csv('fertilizer.csv')

    nr = df[df['Crop'] == crop_name]['N'].iloc[0]
    pr = df[df['Crop'] == crop_name]['P'].iloc[0]
    kr = df[df['Crop'] == crop_name]['K'].iloc[0]

    n = nr - N
    p = pr - P
    k = kr - K
    temp = {abs(n): "N", abs(p): "P", abs(k): "K"}
    max_value = temp[max(temp.keys())]
    if max_value == "N":
        if n < 0:
            key = 'NHigh'
        else:
            key = "Nlow"
    elif max_value == "P":
        if p < 0:
            key = 'PHigh'
        else:
            key = "Plow"
    else:
        if k < 0:
            key = 'KHigh'
        else:
            key = "Klow"

    response = Markup(str(fertilizer_dic[key]))

    return render_template('fertilizer-result.html', recommendation=response, title=title)

# # render disease prediction result page

@app.route('/disease-predict', methods=['GET', 'POST'])
def disease_prediction():
    title = 'AgroNexus - Disease Detection'

    if request.method == 'POST':
        if 'file' not in request.files:
            return redirect(request.url)
        file = request.files.get('file')
        if not file:
            return render_template('disease.html', title=title)
        try:
            img = file.read()

            prediction = predict_image(img)

            prediction = Markup(str(disease_dic[prediction]))
            return render_template('disease-result.html', prediction=prediction, title=title)
        except:
            pass
    return render_template('disease.html', title=title)

@app.route('/service',methods=['GET','POST'])
def service():
    title = 'AgroNexus - Services'
    return render_template('services.html',title=title)

@app.route('/about',methods=['GET','POST'])
def about():
    title = 'AgroNexus - About US'
    return render_template('about.html',title=title)
@app.route('/contact',methods=['GET','POST'])
def contact():
    title = 'AgroNexus - Contact Us'
    return render_template('contact.html',title=title)
@app.route('/login',methods=['GET','POST'])
def login():
    title = 'AgroNexus - Login'
    return render_template('login.html',title=title)

@app.route('/crop',methods=['GET','POST'])
def crop():
    title = 'AgroNexus - Crop Recommendation'
    return render_template('crop_recom.html',title=title)


#Crop recommendation


DT = pickle.load(open('models/DecisionTree.pkl', 'rb'))
@app.route('/crop_predict',methods=['POST'])
def predict():
    title = 'AgroNexus - Crop Prediction'
    '''
    For rendering results on HTML GUI
    '''
    # df = pd.read_csv('fertilizer.csv')
    int_features = [int(x) for x in request.form.values()]
    final_features = [np.array(int_features)]
    prediction = DT.predict(final_features)[0]
    # prediction=prediction.tostring()

    return render_template('crop_predict.html', recommendation=prediction)


if __name__=='__main__':
    app.run(debug=True);
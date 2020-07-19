const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <meta charset="UTF-8">
  <link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.7.2/css/all.css' integrity='sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr' crossorigin='anonymous'>
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>Pogoda teraz</h2>  
<p>
  <i class='fas fa-thermometer-half' style='color:#059e8a;'></i> 
  <span class='dht-labels'>Temperatura</span>  
  <span id='temperature'>%TEMPERATURE%</span>
  <sup class='units'>&deg;C</sup>
</p>
<p>
  <i class='fas fa-tint' style='color:#00add6;'></i> 
  <span class='dht-labels'>Wilgotność</span>
  <span id='humidity'>%HUMIDITY%</span>  
  <sup class='units'>&#37;</sup>
 </p>
<p>
  <i class='fas fa-fire-alt' style='color:#FF8900;'></i>  
  <span class='dht-labels'>Temp Odczuwalna</span>
  <span id='heatindex'>%HEATIDX%</span>
  <sup class='units'>&deg;C</sup>
</p>
<p>
<i class="fas fa-snowflake" style='color:##2FCFFF;'></i>
  <span class='dht-labels'>Punkt rosy</span>
  <span id='devpoint'>%DEVPOINT%</span> 
  <sup class='units'>&deg;C</sup>
 </p>
<p>
  <i class="fas fa-water" style='color:#4FB2FF;'></i>  
  <span class='dht-labels'>Ilość pary wodnej</span>
  <span id='devpoint'>%ABSOLUTEHUM%</span> 
  <sup class='units'>&#37;</sup>
 </p>
 
<p>
  <i class='fas fa-temperature-high' styl ='color:#059e8a;'></i>
  <span class='dht-labels'>Temperatura jakaś tam</span>
  <span id='temphiha'>%TEMPHIHA%</span> 
  <sup class='units'>&#37;</sup>
 </p>
 
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('temperature').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/temperature', true);
  xhttp.send();
}, 10000 ) ;


setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('humidity').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/humidity', true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('devpoint').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/devpoint', true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('heatindex').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/heatindex', true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('absolutehum').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/absolutehum', true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('absolutehum').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/absolutehum', true);
  xhttp.send();
}, 10000 ) ;


setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById('temphihaehum').innerHTML = this.responseText;
    }
  };
  xhttp.open('GET', '/temphiha', true);
  xhttp.send();
}, 10000 ) ;

</script>
</html>)rawliteral";

const char* getIndexPage()
{
  return index_html;
}

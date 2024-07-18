Este proyecto nace de la idea de realizar un sistema de riego automatizado inspirado en "home assistant"
para lo cual se considero que los componenetes mas optimos serian: 
-ESP32
-RELAY MONOCANAL WIFI - ESP8266
-CAPACITIVE SOIL MOISTURE SENSOR
-MINI BOMBA DE AGUA 5V 80/120 Lh
-PANTALLA LCD I2C 16X2.

Plataforma encargada del manejo del broker mosquitto:
Node-Red

La funcion del proyecto es tal que se coloca el "CAPACITIVE SOIL MOISTURE SENSOR" dentro de una maceta para medir la humedad, esta
humedad es trasladada al "ESP32" el cual imprime la informacion en la "PANTALLA LCD I2C 16X2" y a su vez envia la informacion a node-red 
donde este se encargara de expresarla en un "gauge" propio de la plataforma previamente configurado.

En base a esta informacion se puede elegir si encender el "RELAY MONOCANAL WIFI - ESP8266" que controla el encendido de la bomba de agua para dar incio al riego e ir
viendo como aumenta la humedad de la tierra en la maceta como asi se puede apreciar segun lo detallado en su codigo de programacion. (Codigo_ESP32_Control_Relay).

Este puede encenderse y apagarse de forma manual, o encenderlo y solo se apagara al indicar un porcentaje de humedad igual o superior al 90%.
esto ultimo esta detallado en el codigo final del "ESP32" . (codigo final en funcionamiento). 


los codigos aqui desarrollados conllevan una serie de pruebas paso por paso para verificar el correcto funcionamiento de los componentes,
se realizo de esta manera ya que es el primer contacto con el mundo de los broker, protocolos mqtt, node-red, dashboard, etc.

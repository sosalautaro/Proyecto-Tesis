# Proyecto de Sistema de Riego Automatizado

Este proyecto nace de la idea de realizar un sistema de riego automatizado inspirado en "Home Assistant". Los componentes seleccionados para este proyecto son los siguientes:

- ESP32
- RELAY MONOCANAL WIFI - ESP8266
- CAPACITIVE SOIL MOISTURE SENSOR
- MINI BOMBA DE AGUA 5V 80/120 Lh
- PANTALLA LCD I2C 16X2

La plataforma encargada del manejo del broker Mosquitto es **Node-Red**.

## Funcionamiento del Proyecto

El sistema funciona de la siguiente manera:

1. **Medición de Humedad**:
    - El **CAPACITIVE SOIL MOISTURE SENSOR** se coloca dentro de una maceta para medir la humedad del suelo.
    - Esta información se envía al **ESP32**.

2. **Visualización de Datos**:
    - El **ESP32** imprime la información de humedad en la **PANTALLA LCD I2C 16X2**.
    - También envía la información a **Node-Red**, donde se muestra en un "gauge" configurado en la plataforma.

3. **Control del Riego**:
    - En base a la información recibida, se puede elegir si encender el **RELAY MONOCANAL WIFI - ESP8266** que controla el encendido de la bomba de agua.
    - La bomba de agua riega la planta, y se puede observar cómo aumenta la humedad del suelo en la maceta.

4. **Modos de Operación**:
    - El riego puede activarse y desactivarse manualmente.
    - También puede configurarse para que el sistema se apague automáticamente al alcanzar un porcentaje de humedad igual o superior al 90%. Esto está detallado en el código final del **ESP32**.

## Pruebas y Desarrollo

Los códigos desarrollados para este proyecto conllevan una serie de pruebas paso a paso para verificar el correcto funcionamiento de los componentes. Este enfoque se adoptó debido a que es el primer contacto con el mundo de los brokers, protocolos MQTT, Node-Red, dashboards, etc.

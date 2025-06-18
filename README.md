# Trabajos Prácticos – Introducción a la Programación
Este repositorio reúne los trabajos prácticos realizados durante la cursada de la materia **Introducción a la Programación**

## 📂 Contenido
- 🎰 [Tragamonedas](#-tragamonedas)
- 🎲 [Generala](#-generala)

# 🎰 Tragamonedas

Trabajo práctico N°1  
El objetivo era simular una máquina tragamonedas básica con lógica y entrada por teclado.

## 🎯 Objetivo

- Ingresar entre **1 y 10 monedas**.
- Realizar una tirada por moneda con la tecla **P**.
- En cada tirada se generan **3 números aleatorios** entre 1 y 3.
- Si los 3 números son iguales, la tirada cuenta como ganada.
- Al finalizar, se muestra la cantidad de veces que el jugador ganó.

## 🧠 Conceptos aplicados

- Lógica condicional y bucles
- Validación de entrada del usuario
- Uso de números aleatorios (`rand()`)
- Entrada de teclado con `kbhit()` y `getch()` (Windows)

# 🎲 Generala

Trabajo práctico N°2 para la materia.
Donde se simula una partida de Generala entre el jugador y la computadora.  
Se analizan todas las posibles jugadas para determinar el puntaje más alto de cada tirada.

## 🎯 Objetivo

- Simular una **tirada de 5 dados** para el jugador y la PC.
- Evaluar todas las posibles jugadas:
  - Todo al número (1 a 6)
  - Full (30 puntos)
  - Poker (40 puntos)
  - Escalera (50 puntos)
  - Generala (60 puntos)
- Determinar cuál es la **jugada más alta** por participante.
- Mostrar quién ganó la mano.

## 🧠 Conceptos aplicados

- Uso de **funciones** para modularizar
- Arreglos para representar los dados
- Evaluación de combinaciones
- Comparación de puntajes
- Salida formateada en consola

## 🛠️ Tecnologías usadas

- Lenguaje: C++
- Librerías: `<conio.h>`, `<windows.h>`

## 👨‍💻 Autor

**JulioCZ**  
1° Cuatrimestre – Año 2024  
Tecnicatura en Diseño y Programación de Videojuegos

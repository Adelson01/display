# 📟 Leitura de Tensão com Display OLED - Raspberry Pi Pico

Este projeto faz a leitura de um joystick analógico utilizando o ADC do **Raspberry Pi Pico** e exibe o valor da tensão lida em um **display OLED (SSD1306)** via comunicação I2C.

🔗 **Repositório oficial:** [github.com/Adelson01/display](https://github.com/Adelson01/display.git).
    **LINK DO VIDEO** https://drive.google.com/file/d/1S5nDFP-BUoEj906ivz6LY4CiTGE0el_X/view?usp=drive_link

---

## 📌 Visão Geral

O sistema lê continuamente a tensão do eixo X de um joystick conectado ao GPIO 27, converte o valor ADC em tensão real e exibe graficamente no display OLED. A leitura e exibição são atualizadas a cada 100 ms.

---

## 💡 Funcionalidades

- Leitura do ADC com resolução de 12 bits.
- Conversão da leitura ADC para tensão (0 V a 3.3 V).
- Exibição da tensão com interface simples e limpa.
- Atualização constante no display OLED SSD1306.

---

## 🔌 Conexões do Hardware

| Componente         | GPIO (Pico) |
|--------------------|-------------|
| OLED - SDA         | GPIO 14     |
| OLED - SCL         | GPIO 15     |
| Joystick - Eixo X  | GPIO 27     |

---

## 📂 Estrutura do Projeto

```
display/
├── main.c               # Código principal
├── inc/
│   ├── ssd1306.h        # Biblioteca do display
│   └── font.h           # Fonte para o display
├── CMakeLists.txt       # Arquivo de build para o Pico SDK
└── README.md            # Este documento
```

---

## ⚙️ Requisitos

- Raspberry Pi Pico
- Display OLED SSD1306 (I2C)
- Joystick analógico
- Cabos jumper
- SDK do Raspberry Pi Pico configurado no ambiente

---

## 🚀 Como Usar

1. Clone o repositório:
   ```bash
   git clone https://github.com/Adelson01/display.git
   cd display
   ```

2. Crie a pasta de build e compile:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Copie o arquivo `.uf2` gerado para a Raspberry Pi Pico (modo bootloader via USB).

---

## 👩‍💻 Contribuições

| Nome        | Responsabilidade                                           |
|-------------|------------------------------------------------------------|
| **Danielli**  | Desenvolvimento da lógica de exibição no display OLED       |
| **Guilherme** | Implementação da leitura do ADC e conversão da tensão       |
| **Adelson**   | Revisão, organização e correção geral do código             |

---

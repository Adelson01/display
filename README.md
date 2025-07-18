Projeto: Leitura de Tensão via Joystick com Exibição em Display OLED
Este projeto utiliza a placa Raspberry Pi Pico, um joystick analógico e um display OLED SSD1306 via I2C para exibir, em tempo real, a tensão lida de um eixo do joystick.

📌 Descrição
O programa realiza:

Leitura contínua do pino analógico conectado ao eixo X do joystick usando o ADC da placa.

Conversão da leitura digital em uma tensão real (0V a 3.3V).

Exibição do valor da tensão no display OLED com atualização contínua.

💡 Funcionalidades
Leitura analógica com precisão de 12 bits (0 a 4095).

Conversão da leitura ADC em tensão (com base em Vref = 3.3V).

Interface gráfica simples e clara no display OLED:

Retângulo delimitador

Título "TENSAO"

Valor da tensão em volts (ex: 1.65 V)

📦 Estrutura do Projeto
bash
Copiar
Editar
.
├── main.c              # Código principal do projeto
├── inc/
│   ├── ssd1306.h       # Biblioteca para controle do display OLED
│   └── font.h          # Fontes utilizadas no display
├── CMakeLists.txt      # Arquivo de build para o Pico SDK
└── README.md           # Este documento
🔧 Requisitos
Raspberry Pi Pico

Display OLED 128x64 (driver SSD1306, I2C)

Joystick analógico (eixo X conectado ao GPIO 27)

SDK do Raspberry Pi Pico (pico-sdk)

⚙️ Ligações
Componente	GPIO Pico
Display SDA	GPIO 14
Display SCL	GPIO 15
Joystick Eixo X	GPIO 27

👩‍💻 Contribuições
Nome	Responsabilidade
Danielli	Elaboração da lógica gráfica e interface com o display OLED
Guilherme	Implementação e configuração da leitura do ADC para o joystick
Adelson	Revisão geral do código, organização estrutural e correções

🚀 Como Usar
Clone este repositório:

bash
Copiar
Editar
git clone (https://github.com/Adelson01/display.git)
Compile com o SDK do Raspberry Pi Pico:

bash
Copiar
Editar
mkdir build && cd build
cmake ..
make
Carregue o .uf2 na Pico via USB.


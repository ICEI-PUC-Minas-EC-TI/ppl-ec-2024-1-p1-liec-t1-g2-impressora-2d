
# Materiais

* 1x ESP32: Microcontrolador responsável pelo controle da impressora e comunicação via Bluetooth.
* 2x Motores de Passo 28BYJ-48 com Controlador ULN2003AN: Utilizados para mover a caneta nas direções X e Y, permitindo o desenho preciso.
* 1x Servo Motor SG90: Controla a subida e descida da caneta, essencial para iniciar e interromper o desenho.
* Protoboard: Utilizado para montar os circuitos eletrônicos de forma prática e segura.
* Cabos: Fios de conexão para ligar os componentes eletrônicos entre si e com o ESP32.
* Chapa de MDF: utilizado para apoiar os componentes.
* Rolamentos: foram utilizados 5 rolamentos conectados a polias por onde passava a corda, e outros 2 rolamentos na peça principal para mover a base da caneta.
* Peças impressas em 3d: houve a necessidade da impressão de algumas peças, que foram usadas como suporte para os demais itens.
* barbante e elastico: utilizado para mover a caneta.

# Desenvolvimento

 O desenvolvimento da impressora 2D foi realizado em várias etapas, cada uma contribuindo para a construção e funcionamento do dispositivo. Cada membro do grupo desempenhou um papel específico e essencial para o sucesso do projeto, conforme detalhado a seguir.

### 1. Definição de Requisitos
 O primeiro passo foi a definição clara dos requisitos do projeto. O objetivo era criar uma impressora capaz de realizar desenhos pré-programados e permitir o controle manual da caneta através de um aplicativo móvel. A definição de requisitos envolveu a colaboração de todos os membros do grupo para garantir que todas as necessidades e funcionalidades desejadas fossem identificadas.

Responsáveis: Todos os membros participaram da definição dos requisitos.

### 2. Design
A fase de design foi crucial para estabelecer a estrutura física da impressora e o funcionamento do software.

#### Design da Impressora: 
Flávio Guto Teixeira Bezerra e Fernando Augusto Palhares Barbosa projetaram a estrutura da impressora, incluindo a disposição dos motores e o suporte da caneta. O design foi pensado para ser compacto e eficiente, facilitando a montagem e o funcionamento.

#### Design do Aplicativo: 
Rafael Filardi Caldeira foi responsável pelo design e desenvolvimento do aplicativo no App Inventor. Ele criou uma interface amigável que permite a seleção de desenhos pré-definidos e o controle manual da caneta.

### 3. Implementação
A implementação envolveu a montagem física da impressora e a programação necessária para o seu funcionamento.

#### Montagem Física da Impressora: 
Flávio Guto Teixeira Bezerra e Kaylaine Sthephany Machado de Almeida lideraram a montagem dos componentes físicos, como os motores de passo e o servo motor. Eles garantiram que todos os componentes fossem integrados de maneira eficiente.

#### Programação do ESP32: 
João Pedro Ferreira Gomes e Fernando Augusto Palhares Barbosa foram responsáveis pela programação do ESP32, que incluiu o desenvolvimento do código para controlar os motores e receber comandos do aplicativo via Bluetooth. Flávio Guto Teixeira Bezerra também contribuiu na programação do ESP32, assegurando que os motores respondessem corretamente aos comandos.

#### Programação Geral e Coordenação: 
Fernando Augusto Palhares Barbosa, como Scrum Master, coordenou a programação geral e a montagem, garantindo que o projeto fosse executado conforme o planejamento. Ele também participou da programação, contribuindo para a integração do software e hardware.

#### Desenvolvimento do Aplicativo: 
Rafael Filardi Caldeira programou o aplicativo, criando as funcionalidades de seleção de imagens e controle manual da caneta. Ele garantiu que o aplicativo fosse intuitivo e fácil de usar.

### 4. Integração
A fase de integração foi essencial para assegurar que todos os componentes funcionassem em conjunto de forma coesa.

#### Integração de Hardware e Software: 
Todos os membros participaram da integração dos componentes físicos com o software. Isso incluiu a verificação da comunicação entre o ESP32 e o aplicativo, e o ajuste dos movimentos dos motores para garantir a precisão do desenho.

#### Testes de Integração: 
João Pedro Ferreira Gomes e Flávio Guto Teixeira Bezerra realizaram testes para assegurar que o código do ESP32 estivesse funcionando corretamente com os motores e a interface Bluetooth. Rafael Filardi Caldeira testou o aplicativo para garantir que os comandos fossem transmitidos corretamente e que a interface fosse funcional.

### 5. Testes
Testes rigorosos foram realizados para garantir que a impressora operasse conforme os requisitos definidos.

#### Testes de Funcionalidade:
Foram realizados testes de desenhos para garantir que a impressora pudesse desenhar imagens pré-definidas com precisão e que o controle manual funcionasse corretamente. João Pedro Ferreira Gomes e Flávio Guto Teixeira Bezerra lideraram os testes de funcionalidade.

#### Testes de Desempenho: 
Foram realizados testes de longa duração para avaliar a resistência dos componentes e a consistência do desempenho. Fernando Augusto Palhares Barbosa e Kaylaine Sthephany Machado de Almeida foram responsáveis por monitorar e registrar os resultados dos testes.

### 6. Documentação e Manutenção
Após a conclusão dos testes, foi realizada a documentação detalhada do projeto e foram feitas as devidas manutenções.

#### Documentação no GitHub: 
João Pedro Ferreira Gomes, Victor Hugo Nunes Lima e Kaylaine Sthephany Machado de Almeida documentaram todas as etapas do projeto no GitHub, incluindo o código, o design e a montagem. A documentação detalhada facilita a replicação do projeto por outros interessados.

#### Compras e Organização Financeira:
Victor Hugo Nunes Lima geriu a compra de materiais e a organização financeira, garantindo que todos os componentes necessários fossem adquiridos dentro do orçamento.

## Desenvolvimento do Aplicativo

### Interface

O aplicativo possui duas telas, sendo uma principal com todas as funçoes e outra para selecionar o disporsitivo bluetooth.

### Código

O software foi desenvolvido com o foco de simplificar e evitar possíveis interferências externas na comunicação. A comunicação é feita através do Bluetooth, onde todo o processamento e controle são realizados pelo ESP32. Foi definido que cada valor enviado pelo aplicativo para o ESP32 representaria uma sequência de comandos que seriam executados.

## Desenvolvimento do Hardware

### Montagem

A escolha do projeto resultou em uma montagem mais simples, mas embora a parte física fosse mais fácil de montar, o desenvolvimento do código acabou se tornando mais complexo.

Inicialmente, adquirimos todos os materiais seguindo um projeto já desenvolvido por outra pessoa. Quando a montagem do Arduino juntamente com a placa controladora foi concluída, não foi possível implementar um software para controle da impressora.

Reunimo-nos novamente e adaptamos o projeto para uso de outros controladores. Dessa forma, conseguimos fazer com que tudo se comunicasse, e agora já é possível controlar os motores através do aplicativo.

Ainda enfrentamos dificuldades para fazer a impressora se mover para os lados corretamente, sendo uma questão tanto de proporção entre a rotação dos motores quanto tensão do elástico e tamanho do barbante. Não conseguimos chegar a um resultado que faça uma linha completamente reta para os lados, mas já temos um resultado bastante positivo.

### Desenvolvimento do Código

Descreva como foi o desenvolvimento do código do arduino/ESP.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.

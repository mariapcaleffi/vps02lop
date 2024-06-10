# avaliação lop 10/06/2024

📚 Repositório criado para avaliação de LOP, do curso Desenvolvimento de Sistemas do SENAI

### Exercícios:


|1.RELATÓRIO DE VIAGENS 🚗|
|:-:|
|*Como integrante do time de programadores da empresa XPTO, você possui como um de seus clientes a empresa ACME e está trabalhando em diversos projetos nos setores de Produção, Logística e Qualidade, os projetos serão descritos a seguir e cada um possui desafios a serem cumpridos.*|
|1. Crie uma função que calcule o valor total do reembolso, de acordo com as regras de negócio da empresa o cálculo é realizado multiplicando o preço do litro do combustível pela distância percorrida dividido por 3, pois a empresa reembolsa 33.33% ou 1/3 do valor do combustível pela distância.|
|2. Aplique esta função para calcular o total e mostrar na tela o resultado na tabela, conforme o programa já mostra, além disso calcule o total geral que a empresa vai ter que reembolsar e mostre na tela.|
|3. Altere a função mostrarDados() para que separe os funcionários pelo nome e mostre também o total do reembolso de cada um.|
|4. Além de mostrar os resultados na tela, faça com que o programa crie um arquivo de saída do tipo markdown chamado RelatorioViagens.md mostrando os dados em uma tabela e destacando os totais gerais e totais de cada funcionário, conforme o arquivo presente neste repositório.|

|2. PRODUÇÃO DE EXPLOSIVOS 🧨|
|:-:|
|*As máquinas de produção de explosivos TNT possuem um sistema que envia para um arquivo CSV a data, a hora e o número da máquina de cada produto acabado*|
```
Exemplo:
data,hora,maquina
01/05/2024;08:00;1
01/05/2024;20:30;2
01/05/2024;09:00;1
02/05/2024;08:25;3
02/05/2024;20:55;2
02/05/2024;09:25;4
03/05/2024;08:50;1
```
||
|:-:|
|1. Desenvolva um programa chamado chamdo producao.c que leia os dados deste arquivo e mostre na tela quantos exposívos foram produzidos por cada uma das máquinas|
|2. Ainda no programa chamado chamdo producao.c salve um relatório chamado explosivos.md com uma tabela resumindo quantos produtos foram produzidos por dia e por máquina|

|3. PROCESSAMENTO DE QUALIDADE 🔧|
|:-:|
|Após testes realizados em amostras de produtos é gerado um arquivo com diversos parâmetros|
```
numero_de_serie;resistencia;durabilidade
1243124;67;46
1243128;62;25
1243156;61;8
1243189;77;17
```
||
|:-:|
|1. Desenvolva um programa chamado chamdo qualidade.c que leia os dados deste arquivo e mostre na tela uma analize a média de resistência e a media de durabilidade dos produtos, destaque os produtos com maior e menor resistência, destaque os produtos com maior e menor durabilidade, informe se existem mais produtos acima ou abaixo das médias.|
|2. O mesmo programa deve salvar a análise em um arquivo chamado qualidade.md|



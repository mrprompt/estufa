# Estufa

Projeto de estufa com com acompanhamento de umidade de solo, temperatura ambiente e interna e controle de iluminação.

## Material

- 1x módulo relé 5v
- 4x sensores de solo
- 2x sensores de temperatura
- 1x tela lcd com i2c
- 1x lâmpada
- 1x bocal de lâmpada

## Conexão

- Ligar pino de dados do sensor de temperatura interna na D12
- Ligar pino de dados do sensor de temperatura externa na D11
- Ligar pinos de dados dos sensores de umidade de solo nos pinos A0, A1, A2 e A3
- Ligar pino SDA do I2C no pino A4
- Ligar pino SCL do I2C no pino A5
- Ligar pino de dados do módulo relé na D9

## Funcionamento

A estufa constantemente analisa a umidade do solo com os sensores e mostra o percentual no display.
O relé liga a luz (ou outro dispositivo) no horário configurado no código: 4h liga, 20h desliga.

## Configurando a data e hora

Para configurar a data, é necessário editar o arquivo **clock.ino** e ajustar os parâmetros necssários.
Após salvar o arquivo, descomente a chamada à funçào dentro da função **setup**. Finalmente, após subir o código a data estará ajustada, comente novamente a chamada para que a hora não seja novamente reajustada.

#### Licença GPL

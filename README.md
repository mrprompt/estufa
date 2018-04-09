# Estufa

Projeto de estufa com com acompanhamento de umidade de solo, 
temperatura ambiente e interna e controle de iluminação.

## Material

- 1x módulo relé 5v
- 4x sensores de solo
- 2x sensores de temperatura
- 1x tela lcd com i2c
- 1x lâmpada
- 1x bocal de lâmpada

## Conexão

TODO

## Configurando a data

Para configurar a data, é necessário editar o arquivo **clock.ino**
e ajustar os parâmetros necssários.
Após salvar o arquivo, descomente a chamada à funçào dentro da função
**setup**. Finalmente, após subir o código a data estará ajustada, comente
novamente a chamada para que a hora não seja novamente reajustada.

#### Licença GPL

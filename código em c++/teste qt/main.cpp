#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Cria um bot�o com o texto "Hello, World!".
    QPushButton button("Hello, World!");

    // Conecta o sinal "clicked" do bot�o a uma fun��o lambda que exibe uma mensagem.
    QObject::connect(&button, &QPushButton::clicked, []() {
        QMessageBox::information(nullptr, "Mensagem", "Ol�, Qt!");
    });

    // Exibe o bot�o na tela.
    button.show();

    // Inicia o loop de eventos da aplica��o Qt.
    return app.exec();
}
Este

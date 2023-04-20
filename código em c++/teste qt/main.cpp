#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Cria um botão com o texto "Hello, World!".
    QPushButton button("Hello, World!");

    // Conecta o sinal "clicked" do botão a uma função lambda que exibe uma mensagem.
    QObject::connect(&button, &QPushButton::clicked, []() {
        QMessageBox::information(nullptr, "Mensagem", "Olá, Qt!");
    });

    // Exibe o botão na tela.
    button.show();

    // Inicia o loop de eventos da aplicação Qt.
    return app.exec();
}
Este

#include <iostream> //saida e entrada padrão
#include <conio.h> //para configurar teclas do teclado
#include <ctime> //para alimentar uma semente
#include <cstdlib> //biblioteca para alimentar o srand

int jogar = 1;//variável global

using namespace std;

int menu();
int escolha();
int logo();
int jogo();
int papel();
int pedra();
int tesoura();


int main()
{

    menu();
    jogo();

    system("pause");//Só sai do programa se o usuario apertar

    return 0;
}

int menu()
{


    logo();
    escolha();


}

int escolha(){

    int tecla ;

            cout <<"***********************************************************************************************************\n";
            cout <<"*                                            PLAYGAME                                                     *\n";
            cout <<"***********************************************************************************************************\n\n";
            cout <<"                                           CLOSE the GAME                                                    ";
            cout <<""<<jogar;
    do{
        tecla = getch();

        if(tecla == 80){
            system("cls");//limpa tela
            logo();
            jogar = 0;
            cout <<"\n";
            cout <<"                                             PLAYGAME                                                \n";
            cout <<"***********************************************************************************************************\n";
            cout <<"*                                          CLOSE the GAME                                                 *\n";
            cout <<"***********************************************************************************************************\n";
            cout <<""<<jogar;
        }else if(tecla == 72){
            system("cls");
            jogar = 1;
            logo();
            cout <<"***********************************************************************************************************\n";
            cout <<"*                                            PLAYGAME                                                     *\n";
            cout <<"***********************************************************************************************************\n\n";
            cout <<"                                           CLOSE the GAME                                                    ";
            cout <<""<<jogar;
        }
    }while(tecla != 13);

}
int logo(){
        //Essa função mostra um menu no inicio do jogo.
    cout << "  JJJJJJJJJ    OOOOOOO     KKKK  KKkkk  EEEEEEEEEEEEEE   NNNNNN      NNNNNN    PPPPPPPPPP    OOOOOOO " << endl;
    cout << "  JJJJJJJJJ   OOOOOOOOO    KKKK  KKKkk  EEEEEEEEEEEEEE   NNNNNNN     NNNNNN    PPPPPPPPPPP  OOOOOOOOO " << endl;
    cout << "       JJ    OOOOOOOOOOO   KKKK  KKKk   EEE             NNNNNNNN    NNNNNN    PPP    PPP  OOOOOOOOOOO " << endl;
    cout << "       JJ    OOOO   OOOO   KKKK  KKKK   EEE             NNNNNNNNN   NNNNNN    PPP    PPP  OOOO   OOOO " << endl;
    cout << "       JJ    OOOO   OOOO   KKKK  KKKK   EEEEEEEEEEE     NNNNNNNNNN  NNNNNN    PPPPPPPPPP  OOOO   OOOO " << endl;
    cout << "       JJ    OOOO   OOOO   KKKK KKKK    EEEEEEEEEEE     NNNNNNNNNNN NNNNNN    PPPPPPPPP   OOOO   OOOO " << endl;
    cout << "       JJ    OOOO   OOOO   KKKKKKKK     EEE             NNNNNNNNNNNNNNNNN    PPP         OOOO   OOOO " << endl;
    cout << "JJJ    JJ    OOOO   OOOO   KKKKKKKK     EEE             NNNNNN NNNNNNNNNN    PPP         OOOO   OOOO " << endl;
    cout << "JJJJJJJJ     OOOOOOOOOOO   KKKK  KKKK   EEEEEEEEEEEEEE  NNNNNN  NNNNNNNNN    PPP         OOOOOOOOOOO " << endl;
    cout << "JJJJJJJ       OOOOOOO     KKKK   KKKK  EEEEEEEEEEEEEE  NNNNNN   NNNNNNNN    PPP          OOOOOOO " << endl;
    cout << std::endl;
}

int jogo(){

    srand(time(NULL));//seed para alimentar um número aleatorio

    system("cls");

    int maquina = 0, jogador = 0, i = 1;

    if(jogar == 0){
        cout <<"Obrigado pelo seu tempo";
    }

    if(jogar == 1){

        while(i > 0){
            cout <<"0 - pedra, 1  - papel, 2 - tesoura:\n";
            cin >> jogador;
            system("cls");
            maquina = rand()%3;

            if(maquina == 0){
                system("cls");
                pedra();
            }else if(maquina == 1){
                system("cls");
                papel();
            }else if(maquina ==2){
                system("cls");
                tesoura();
            }
            cout<<""<< maquina;
            i = i+1;
        }

    }
}
int papel(){

    std::cout << "    _______ " << std::endl;
    std::cout << "---'   ____)____ " << std::endl;
    std::cout << "          ______) " << std::endl;
    std::cout << "          _______) " << std::endl;
    std::cout << "         _______) " << std::endl;
    std::cout << "---.__________) " << std::endl;
    std::cout << std::endl;
    std::cout << "       PAPEL! " << std::endl;

}
int tesoura(){

    std::cout << "    _____ " << std::endl;
    std::cout << "---'   ____)____ " << std::endl;
    std::cout << "          ______) " << std::endl;
    std::cout << "       __________) " << std::endl;
    std::cout << "      (____) " << std::endl;
    std::cout << "      (____) " << std::endl;
    std::cout << "      (____) " << std::endl;
    std::cout << "---.__(___) " << std::endl;
    std::cout << std::endl;
    std::cout << "     TESOURA! " << std::endl;
}
int pedra(){
    std::cout << "   _______ " << std::endl;
    std::cout << "--'   ____) " << std::endl;
    std::cout << "      (_____) " << std::endl;
    std::cout << "      (_____) " << std::endl;
    std::cout << "      (____) " << std::endl;
    std::cout << "--.__(___) " << std::endl;
    std::cout << std::endl;
    std::cout << "      PEDRA! " << std::endl;
}


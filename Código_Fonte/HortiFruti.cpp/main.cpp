#include <iostream>
using namespace std;

int main() {
    //exibição do menu intuitivo do hortifruti:
    cout << "----------------------------------------------------------" << endl;
    cout << "\t\t\tHORTI FRUTI" << endl;
    cout << "----------------------------------------------------------" << endl;


    //Definição das strings:
    string nome_fun, sobrenome, anoNasc, noFav;
    //nome do funcionário, sobrenome, o ano de nascimento e o número favorito.
    cout << "Insira o nome do funcionario: \n---->";
    cin >> nome_fun;
    cout << "Insira o sobrenome do funcionario: \n---->";
    cin >> sobrenome;
    cout << "Insira o ano de nascimento do funcionario: \n---->";
    cin >> anoNasc;
    cout << "Insira o numero favorito do funcionario: \n---->";
    cin >> noFav;

    //A string (usuario) recebe a string anterior "nome_fun" + sobrenome + anoNasc;
    string usuario = nome_fun + sobrenome + anoNasc;
    //A string (senha) recebe a string anterior "nome_fun" + sobrenome + anoNasc;
    string senha = nome_fun + sobrenome + noFav;

    //Exibicção do login temporário e senha temporária:
    cout << "O usuario e: " << usuario << endl;
    cout << "A senha temporaria do usuario e: " << senha << endl;

    //Criação e definição da string para inserir o usuario e inserir a senha;
    string input_usuario, input_senha;
    cout << "Insira o usuario: \n---->";
    cin >> input_usuario;
    cout << "Insira a senha: \n---->";
    cin >> input_senha;

    /* Estrura de condição IF que indica se o usuário NÃO É IGUAL a usuario e input_senha NÃO É IGUAL a senha, exibe: Login falhou! Tente novamente! */
    if (input_usuario != usuario || input_senha != senha) {
        cout << "Login falhou! Tente novamente." << endl;
        return 0;
    }
    
    //Caso a estura se acima for falsa, executa o código abaixo:
    cout << "Login bem-sucedido!" << endl;
    /*criação da matriz em formato de string, com  */
    string frutas[5][3] = {
        {"Banana", "2.7", "200"},
        {"Maca", "2.0", "200"},
        {"Laranja", "1.7", "200"},
        {"Limão", "5.1", "200"},
        {"Abacaxi", "6.5", "200"}
    };

    string legumes[5][3] = {
        {"Cebola", "3.2", "100"},
        {"Cenoura", "3.5", "100"},
        {"Alho", "3.2", "100"},
        {"Alho-poro", "2.1", "100"},
        {"Chuchu", "2.9", "100"}
    };
    
    //Criação do int opcao, que indica qual será a opção selecionada pelo usuário:
    int opcao;
    /*loop do while para verificar se vai continuar utilizando o programa ou não, do (faça) while (enquanto), executa a sequência para ler qual opção o usuário deseja utilizar */  
    do {
        cout << "\nEscolha uma opcao:\n";
        cout << "[1] Compras\n";
        cout << "[2] Estoque\n";
        cout << "[3] Excluir Item (Frutas Ou Legumes)\n";
        cout << "[4] Adicionar Item\n";
        cout << "[5] Sair\n";
        cout << "Digite a opcao desejada: ";
        cin >> opcao;
        
        /*Estrutura condicional SE, indica SE a opção selecionada e lida for igual a 1, executa um bloc de código*/
        if (opcao == 1) {
            double total = 0.0;
            char continuar;
            
             /*loop do while para verificar se vai continuar comprando ou não, do (faça) while (enquanto), executa a ação de Escolher uma opção, selecionar qual é e se continua comprando ou não */  
            do {
                cout << "FRUTAS DISPONIVEIS: " << endl;
                for (int i = 0; i < 5; ++i) {
                    cout << "[" << i + 1 << "] " << frutas[i][0] << " - R$" << frutas[i][1] << " (Quantidade: " << frutas[i][2] << ")" << endl;
                }
                cout << "LEGUMES DISPONIVEIS: " << endl;
                for (int i = 0; i < 5; ++i) {
                    cout << "[" << i + 6 << "] " << legumes[i][0] << " - R$" << legumes[i][1] << " (Quantidade: " << legumes[i][2] << ")" << endl;
                }

                int selec;
                cout << "Digite a opcao que deseja selecionar (ou 0 para sair): \n---->";
                cin >> selec;

                if (selec == 0) break;

                int quantidade;
                if (selec >= 1 && selec <= 5) {
                    cout << "Digite a quantidade: ";
                    cin >> quantidade;
                    total += quantidade * stod(frutas[selec - 1][1]);
                } else if (selec >= 6 && selec <= 10) {
                    cout << "Digite a quantidade: ";
                    cin >> quantidade;
                    total += quantidade * stod(legumes[selec - 6][1]);
                } else {
                    cout << "Opcao invalida!" << endl;
                }

                cout << "Deseja continuar comprando? (s/n): ";
                cin >> continuar;
            } while (continuar == 's');

            cout << "TOTAL A PAGAR: R$" << total << endl;

            string formaPagamento;
            cout << "Escolha a forma de pagamento (dinheiro/cartao): ";
            cin >> formaPagamento;

            if (formaPagamento == "dinheiro") {
                cout << "Pagamento realizado com sucesso em dinheiro!" << endl;
            } else if (formaPagamento == "cartao") {
                cout << "Pagamento realizado com sucesso no cartão!" << endl;
            } else {
                cout << "Forma de pagamento inválida!" << endl;
            }
        } else if (opcao == 2) {
            cout << "FRUTAS DISPONIVEIS: " << endl;
            for (int i = 0; i < 5; ++i) {
                cout << frutas[i][0] << " - R$" << frutas[i][1] << " (Quantidade: " << frutas[i][2] << ")" << endl;
            }
            cout << "LEGUMES DISPONIVEIS: " << endl;
            for (int i = 0; i < 5; ++i) {
                cout << legumes[i][0] << " - R$" << legumes[i][1] << " (Quantidade: " << legumes[i][2] << ")" << endl;
            }
        } else if (opcao == 5) {
            cout << "Saindo..." << endl;
        } else {
            cout << "Opcao inválida!" << endl;
        }
    } while (opcao != 5);

    return 0;
}
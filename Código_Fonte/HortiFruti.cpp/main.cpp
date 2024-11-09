#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <locale.h>
using namespace std;

// Estrutura para Item
struct Item {
    string nome;
    double preco;
    int quantidade;
    int capacidade_inicial; // Adiciona a capacidade inicial do item
};

// Estrutura para Cliente
struct Cliente {
    string nome;
    string cpf;
    string endereco;
    string telefone;
};

// Função para exibir menu
void menu_exibicao() {
    cout << "----------------------------------------------------------" << endl;
    cout << "\t\t\tHORTI FRUTI" << endl;
    cout << "----------------------------------------------------------" << endl;
}

// Função para mostrar os itens
void mostrarItens(const vector<Item>& itens) {
    for (size_t i = 0; i < itens.size(); ++i) {
        cout << "[" << i + 1 << "] " << itens[i].nome << " - R$" << itens[i].preco << " (Quantidade: " << itens[i].quantidade << ")";
        if (itens[i].quantidade < 0.3 * itens[i].capacidade_inicial) {
            cout << " - Necessario comprar";
        }
        cout << endl;
    }
}

//Função para excluir cadastro
void excluirItem(vector<Item>& itens) {
    menu_exibicao();
    cout << "ITENS DISPONIVEIS PARA EXCLUIR: " << endl;
    mostrarItens(itens);

    int selec;
    cout << "Digite o numero do item que deseja excluir: \n---->";
    cin >> selec;

    if (selec > 0 && selec <= itens.size()) {
        itens.erase(itens.begin() + selec - 1);
        cout << "Item excluido com sucesso!" << endl;
    } else {
        cout << "Opcao invalida!" << endl;
    }
}

// Função para adicionar item
void adicionarItem(vector<Item>& itens) {
    Item novoItem;
    cout << "Digite o nome do item: ";
    cin >> novoItem.nome;
    cout << "Digite o preco do item: ";
    cin >> novoItem.preco;
    cout << "Digite a quantidade do item: ";
    cin >> novoItem.quantidade;
    novoItem.capacidade_inicial = novoItem.quantidade; // Define a capacidade inicial

    itens.push_back(novoItem);
    cout << "Item adicionado com sucesso!" << endl;
}

// Função para cadastrar cliente
void cadastrarCliente(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "Digite o nome do cliente: ";
    cin.ignore(); // Limpar o buffer de entrada
    getline(cin, novoCliente.nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin, novoCliente.cpf);
    cout << "Digite o endereco do cliente: ";
    getline(cin, novoCliente.endereco);
    cout << "Digite o telefone do cliente: ";
    getline(cin, novoCliente.telefone);

    clientes.push_back(novoCliente);
    cout << "Cliente cadastrado com sucesso!" << endl;
}

// Função para procurar cliente
void procurarCliente(const vector<Cliente>& clientes) {
    string cpf;
    cout << "Digite o CPF do cliente que deseja procurar: ";
    cin.ignore(); // Limpar o buffer de entrada
    getline(cin, cpf);

    for (const auto& cliente : clientes) {
        if (cliente.cpf == cpf) {
            cout << "Cliente encontrado:\n";
            cout << "Nome: " << cliente.nome << "\nCPF: " << cliente.cpf << "\nEndereco: " << cliente.endereco << "\nTelefone: " << cliente.telefone << endl;
            return;
        }
    }
    cout << "Cliente nao encontrado." << endl;
}

// Função para realizar compras
void realizarCompras(vector<Item>& itens) {
    menu_exibicao();
    double total = 0.0;
    char continuar;

    do {
        cout << "ITENS DISPONIVEIS: " << endl;
        mostrarItens(itens);

        int selec;
        cout << "Digite a opcao que deseja selecionar: \n---->";
        cin >> selec;

        if (selec == 0) break;

        if (selec >= 1 && selec <= itens.size()) {
            int quantidade;
            cout << "Digite a quantidade: ";
            cin >> quantidade;

            if (quantidade <= itens[selec - 1].quantidade) {
                total += quantidade * itens[selec - 1].preco;
                itens[selec - 1].quantidade -= quantidade;
                cout << "Item adicionado ao carrinho!" << endl;
            } else {
                cout << "Quantidade insuficiente no estoque para o item " << itens[selec - 1].nome << ".\n";
            }
        } else {
            cout << "Opcao invalida!" << endl;
        }

        cout << "Deseja continuar comprando? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' && !itens.empty());

    cout << "TOTAL A PAGAR: R$" << total << endl;

    // Chama a Função de pagamento
    string formaPagamento;
    cout << "Escolha a forma de pagamento (dinheiro/cartao): ";
    cin >> formaPagamento;

    if (formaPagamento == "dinheiro") {
        cout << "Pagamento realizado com sucesso em dinheiro!" << endl;
    } else if (formaPagamento == "cartao") {
        cout << "Pagamento realizado com sucesso no cartao!" << endl;
    } else {
        cout << "Forma de pagamento invalida!" << endl;
    }
}

// Função de estoque
void estoque(const vector<Item>& itens) {
    menu_exibicao();
    cout << "ITENS DISPONIVEIS: " << endl;
    mostrarItens(itens);
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese"); //uso de letras e acentuação do portugues br
    menu_exibicao();

    // Inicializa itens
    vector<Item> itens = {
        {"Banana", 2.7, 200},
        {"Maçã", 2.0, 200},
        {"Laranja", 1.7, 200},
        {"Limão", 5.1, 200},
        {"Abacaxi", 6.5, 200},
        {"Cebola", 3.2, 100},
        {"Cenoura", 3.5, 100},
        {"Alho", 3.2, 100},
        {"Alho-poro", 2.1, 100},
        {"Chuchu", 2.9, 100}
    };

    // Inicializa clientes
    vector<Cliente> clientes;

    // Menu principal
    int opcao;
    do {
        cout << "\nEscolha uma opcao:\n";
        cout << "[1] Compras\n";
        cout << "[2] Estoque\n";
        cout << "[3] Excluir Item\n";
        cout << "[4] Adicionar Item\n";
        cout << "[5] Cadastrar Cliente\n";
        cout << "[6] Procurar Cliente\n";
        cout << "[7] Sair\n";
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                realizarCompras(itens);
                break;
            case 2:
                estoque(itens);
                break;
            case 3:
                excluirItem(itens);
                break;
            case 4:
                adicionarItem(itens);
                break;
            case 5:
                cadastrarCliente(clientes);
                break;
            case 6:
                procurarCliente(clientes);
                break;
            case 7:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    } while (opcao != 7);

    return 0;
}

#include <iostream>

using namespace std;

int main() {
	int a;
	cout << "-------Biblioteca Virtual-------" << endl;
	cout<<endl;
	cout<<"Alunos:"<<endl;
	cout<<"Daniel Alves Sanches"<<endl;
	cout<<"Julia Mello Lopes Gonçalves"<<endl;
	cout<<"Leonardo de Oliveica Campos"<< endl;
	cout<<"Lucas de Souza Gontijo"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"MENU"<<endl;
	cout<<endl;
	cout<<"1-Sistema para Colaborador"<<endl;
	cout<<"2-Sistema para Usuário"<<endl;
	cin>>a;
	switch (a)
	{
	case 1:
		//caminho do sistema de colaboradores
		cout<<""<<endl;
		break;
	case 2:
		//caminho do sistema de usuário
		cout<<""<<endl;
		break;
	default:
		cout<<"Digite uma opção válida"<<endl;
		break;
	}
	return 0;
}
#include <iostream>
using namespace std;
#include <string>
#define N 1000
struct people {
	string name;
	string gender;
	int age;
	string phone;
	string address;
};
struct  Addressbooks {
	struct people p[N];
	int m_size;
};
// ����û�
void add_p(Addressbooks *ads, string name, string gender, int age, string phone, string address) {
	if (ads->m_size == N) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	ads->p[ads->m_size].name = name;
	ads->p[ads->m_size].gender = gender;
	ads->p[ads->m_size].age = age;
	ads->p[ads->m_size].phone = phone;
	ads->p[ads->m_size].address = address;
	ads->m_size++;
}


//��ѯ1ȫ��
void selectAll(Addressbooks *ads) {
	
	for (int i = 0; i < ads->m_size; i++)
	{
		cout << "������" << ads->p[i].name << "�Ա�:" << ads->p[i].gender << "���䣺" << ads->p[i].age << "�绰��" << ads->p[i].phone << "��ַ��" << ads->p[i].address << endl;
	}
}
// ������ɾ��
void delete_p(Addressbooks* ads, string name) {
	int count = 0;
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->p[i].name == name) {
			for (int j = i; j < ads->m_size; j++)
			{
				ads->p[j] = ads->p[j + 1];
				ads->m_size--;
				count++;
			}
		}
	}
	if (count > 0) cout << "ɾ���ɹ�,����Ϊ:" << count << endl;
	else cout << "�����ڸ��û�" << endl;
}
//��������ѯ
int selectName(Addressbooks *ads, string name) {
	int i = 0;
	int count = 0;
	for ( i = 0; i < ads->m_size; i++)
	{
		if (ads->p[i].name == name) {
			cout << "������" << ads->p[i].name << "�Ա�:" << ads->p[i].gender << "���䣺" << ads->p[i].age << "�绰��" << ads->p[i].phone << "��ַ��" << ads->p[i].address << endl;
			count ++ ;
		}
	}
	if (count == 0) {
		cout << "�����ڸ��û�" << endl;
		return -1;
	}
	else return  1;
}
// �������޸�
void edittName(Addressbooks *ads) {
	string name;
	string gender;
	int age;
	string phone;
	string address;
	cout << "������Ҫ�޸ĵ�����" << endl;
	cin >> name;
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->p[i].name == name) {
			cout << "�������Ա�" << endl;
			cin >> gender;
			ads->p[i].gender = gender;
			cout << "���������䣺" << endl;
			cin >> age;
			ads->p[i].age = age;
			cout << "�������ֻ��ţ�" << endl;
			cin >> phone;
			ads->p[i].phone = phone;
			cout << "�������ַ��" << endl;
			cin >> address;
			ads->p[i].address = address;
		}
	}
	
		

}
//ɾ������
void deleteAll(Addressbooks *ads) {
	ads->m_size = 0;
}
void mulu() {
	cout << "ͨѶ¼����ϵͳ" << endl;
	cout << "����û�����1" << endl;
	cout << "ɾ��ָ������Ϣ2" << endl;
	cout << "��ʾȫ����ϵ��3" << endl;
	cout << "����ָ����ϵ��4" << endl;
	cout << "�޸�ָ����ϵ��5" << endl;
	cout << "���������ϵ��6" << endl;
	cout << "�˳�ͨѶ¼0" << endl;
}
int main() 
{
	Addressbooks ads;
	ads.m_size = 0;
	int a = 0;
	string name;
	string gender;
	int age;
	string phone;
	string address;
	Flag:
	mulu();
	cin>> a;
	switch (a)
	{
	case 0:
		return 0;
	case 1:
		cout << "������������" << endl;
		cin >> name;
		cout << "�������Ա�" << endl;
		cin >> gender;
		cout << "���������䣺" << endl;
		cin >> age;
		cout << "������绰��" << endl;
		cin >> phone;
		cout << "�������ַ��" << endl;
		cin >> address;
		cout << "��ӳɹ�" << endl;
		add_p(&ads, name, gender, age, phone, address);
		break;
	case 2:
		cout << "��������" << endl;
		cin >> name;
		delete_p(&ads, name);
		break;
	case 3:
		selectAll(&ads);
		break;
	case 4:
		cout << "�����ѯ����" << endl;
		cin >> name;
		selectName(&ads,name);
		break;
	case 5: 
		edittName(&ads);
		break;
	case 6:
		deleteAll(&ads);
	}
	selectAll(&ads);
	cout << "����Ŀ¼,����0" << endl;
	cin >> a;
	if (a == 0) {
		system("cls");
		goto Flag;
	}
	system("pause");
	return 0;

}
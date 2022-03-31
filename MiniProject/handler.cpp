
#include"handler.h"
#include"Item.h"


Handler::Handler() {}

void Handler::Menu_Main(void)
{
	cout << endl;
	cout << "-----Menu-----" << endl;
	cout << endl;
	cout << "1. BOM" << endl;
	cout << "2. 생산계획" << endl;
	cout << "3. 공정" << endl;
	cout << "4. 불량정보확인" << endl;
	cout << "5. 프로그램 종료" << endl << endl;
}

void Handler::Init_Sample_ItemInfo(void)
{
	CPU cpu1("CPU1", "CPU001", "20220330-CP1-001");
	CPU cpu2("CPU2", "CPU002", "20220330-CP2-001");
	CPU cpu3("CPU3", "CPU003", "20220330-CP3-001");

	MB mb1("MB1", "MB001", "20220330-MB1-001");
	MB mb2("MB2", "MB002", "20220330-MB2-001");
	MB mb3("MB3", "MB003", "20220330-MB3-001");

	Memorry ram1("ram1", "ram001", "20220330-ram1-001");
	Memorry ram2("ram2", "ram002", "20220330-ram2-001");
	Memorry ram3("ram3", "ram003", "20220330-ram3-001");

	HDD hdd1("hdd1", "hdd001", "20220330-hdd1-001");
	HDD hdd2("hdd2", "hdd002", "20220330-hdd2-001");
	HDD hdd3("hdd3", "hdd003", "20220330-hdd3-001");

	SSD ssd1("ssd1", "ssd001", "20220330-ssd1-001");
	SSD ssd2("ssd2", "ssd002", "20220330-ssd2-001");
	SSD ssd3("ssd3", "ssd003", "20220330-ssd3-001");

	Power pow1("pow1", "pow001", "20220330-pow1-001");
	Power pow2("pow2", "pow002", "20220330-pow2-001");
	Power pow3("pow3", "pow003", "20220330-pow3-001");

	Case case1("case1", "case001", "20220330-case1-001");
	Case case2("case2", "case002", "20220330-case2-001");
	Case case3("case3", "case003", "20220330-case3-001");

	Software os1("os1", "os001", "20220330-os1-001");
	Software os2("os2", "os002", "20220330-os2-001");
	Software os3("os3", "os003", "20220330-os3-001");

	product2* stub[100];

	stub[0] = new product2("PC01", cpu1, mb2, ram1, hdd3, ssd1, pow3, case2, os1);
	//stub[0]->Print_produt();
}


void Handler::Menu_ManufacturePlanning()
{

	int option;
	while (1)
	{
		cout << "==============생산계획==============" << endl;
		cout << "(1) 생산계획 추가" << endl;
		cout << "(2)생산 계획 삭제" << endl;
		cout << "(3)생산 계획 조회" << endl;
		cout << "(4)뒤 로 가 기" << endl;

		cin >> option;
		if (option == 1)
			Add_ManufacturePlanning();
		else if (option == 2)
			Delete_ManufacturePlanning();
		else if (option == 3)
			Show_ManufacturePlanning();
		else
		{
			cout << "잘못입력" << endl;
			break;
		}
	}
}

void Handler::Add_ManufacturePlanning()				//(BOM에서 시리얼번호 받아옴)
{
	string sirial;
	int date;
	int amount;
	string model;

	//제품 받아와서 선택
	cout << "===========================생산계획=============================" << endl;
	///BOM에서 받아와 부품 리스트 출력

	cout << "생산할 Srial번호를 입력하세요 : "; cin >> sirial;
	//생산할 날짜, 개수 입력
	cout << "생산할 날짜를 입력하세요 : "; cin >> date;
	cout << "생산할 개수를 입력하세요 : "; cin >> amount;
	cout << "생산할 모델을 선택해주세요 : "; cin >> model;

	stub[Num_Memproduct++] = new Plan(sirial, date, amount);

	cout << "-------------------------" << endl;
	stub[0]->Print_Plan();
	cout << "-------------------------" << endl;

	//handler에 넘겨줄 생산계획 배열 생성
}

void Handler::Show_ManufacturePlanning()              //모든 계획 출력
{
	cout << "-------------------------" << endl;
	for (int i = 0; i < Num_Memproduct; i++)
		stub[i]->Print_Plan();
	cout << "-------------------------" << endl;
}

void Handler::Delete_ManufacturePlanning()
{
	string sirial;
	cout << "시리얼을 입력하세요" << endl;
	cin >> sirial;

	for (int i = 0; i < Num_Memproduct; i++)
	{
		if (sirial == stub[i]->getMemSrial())
		{
			delete stub[i];						//생산게획 시리얼 검색하여 삭제
			for (int j = i; j < Num_Memproduct; j++)
			{
				stub[j] = stub[j + 1];			//삭제된 배열 뒤에 있는 배열을 한칸 앞으로 삽임
			}
			Num_Memproduct--;
			cout << "계획을 삭제했습니다." << endl;
			return;
		}
	}
	cout << "해당 계획이 없습니다." << endl;
}

///////////////////////////////////////////////////////////bom코드, 생산계획코드, 개수 리턴

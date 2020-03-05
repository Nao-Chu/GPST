/********************************************************************
    > File Name: 10.cpp
    > Author: zzp
    > Created Time: 2020年03月05日 星期四 15时41分41秒
 *******************************************************************/

/*
 * multimap 案例
 * 人员信息有:姓名 年龄 电话 工资等组成
 * 通过 Multimao 进行信息的插入 保存 显示
 * 分部门显示员工信息 显示全部信息
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Worker{
public:
	string mName;
	string mTele;
	int mAge;
	int mSalary;
};
enum{
SALE_DEPATMENT = 1,
DEVELOP_DEPATMENT,
FINACIAL_DEPATMENT
};
// 创建员工
void Create_Worker(vector<Worker>& vWorker){
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++){
		Worker worker;
		worker.mName = "员工";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mTele = "010-88888888";
		worker.mSalary = rand() % 10000 + 10000;
		vWorker.push_back(worker);
	}
}

// 员工分组
void WorkerByGroup(vector<Worker>& vWorker, multimap<int,Worker>& workerGroup){
	// 把员工随机分配不同部门
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++){
		int departID = rand() % 3;
		switch (departID){
			case SALE_DEPATMENT:
				workerGroup.insert(make_pair(SALE_DEPATMENT,*it));
				break;
			case DEVELOP_DEPATMENT:
				workerGroup.insert(make_pair(DEVELOP_DEPATMENT,*it));
				break;
			case FINACIAL_DEPATMENT:
				workerGroup.insert(make_pair(FINACIAL_DEPATMENT,*it));
				break;
			default:
				break;
		}
	}

}
// 打印每一部分员工信息
void PrintWorkerByGroup(multimap<int,Worker>& workerGroup){
	// 打印销售员工信息
	multimap<int,Worker>::iterator it = workerGroup.find(SALE_DEPATMENT);
	// 找当前部门总人数
	int DepartCount = workerGroup.count(SALE_DEPATMENT);

	int num = 0;
	for (multimap<int,Worker>::iterator pos = it; pos != workerGroup.end() && num < DepartCount; pos++,num++){
		cout << "姓名:" << pos->second.mName << "\t年龄:" << pos->second.mAge << "\t电话:" << pos->second.mTele << endl;
	}
}

int main(int argc,char** argv)
{
	vector<Worker> vWorker;
	multimap<int,Worker> workerGroup;
	Create_Worker(vWorker);
	WorkerByGroup(vWorker,workerGroup);
	PrintWorkerByGroup(workerGroup);
	return 0;
}

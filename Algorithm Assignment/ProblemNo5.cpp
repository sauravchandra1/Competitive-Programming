#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 300005
// Structure to mainting the necessary information
struct node{
	int startingKnightNumber;
	int endingKnightNumber;
	int WinnerKnightNumber;
	int fightIndex;
};
// Comparator function to sort according the fight number
class comparatorFunction {
public:
	int operator() (node a, node b) {
		return a.fightIndex > b.fightIndex;
	}
};

int main() {
	int numberOfKnight = 8, numberOfFight = 4;
	int startingIndexOfKnight[] = {3, 3, 2, 1};
	int endingIndexOfKnight[] = {5, 7, 8, 8};
	int winnerKnight[] = {4, 6, 8, 1};

	vector<node> temporaryNodeVector;
	vector<int> inputArray[N];
	vector<pair<pair<int,int>, int>> temporaryQueue;

	// Priority queue to maintain node sorted accoring to the fight number
	priority_queue<node, vector<node>, comparatorFunction> priorityContainer;
	pair<int, int> inputPair;
	

	for (int i = 0; i < numberOfFight; i++) {
		inputPair.first = startingIndexOfKnight[i];
		inputPair.second = endingIndexOfKnight[i];
	
		temporaryQueue.push_back(make_pair(inputPair, winnerKnight[i]));
		inputArray[startingIndexOfKnight[i]].push_back(i);
	}
	
	int i;
	int flag = 0;
	int fightNumber;
	
	node currentFight;

	for (i = 1; i <= numberOfKnight; i++) {
	
		for (int j = 0; j < (int)inputArray[i].size(); j++) {
			fightNumber = inputArray[i][j];
			currentFight.startingKnightNumber = temporaryQueue[fightNumber].first.first;
			currentFight.endingKnightNumber = temporaryQueue[fightNumber].first.second;
			currentFight.WinnerKnightNumber = temporaryQueue[fightNumber].second;
			currentFight.fightIndex = fightNumber;
			priorityContainer.push(currentFight);
		}
	
		if (priorityContainer.empty()) {
			cout << "0 ";
			continue;
		}
	
		while (!priorityContainer.empty()) {
			currentFight = priorityContainer.top();
			
			if (i >= currentFight.startingKnightNumber && i <= currentFight.endingKnightNumber) {
				if (currentFight.WinnerKnightNumber == i) {
			
					while (!priorityContainer.empty()) {
	
						currentFight = priorityContainer.top();
						if (i >= currentFight.startingKnightNumber && i <= currentFight.endingKnightNumber) {
	
							if (currentFight.WinnerKnightNumber == i) {
								temporaryNodeVector.push_back(currentFight);
								priorityContainer.pop();
							}
							else {
								for (auto item : temporaryNodeVector)
									priorityContainer.push(item);
	
								temporaryNodeVector.clear();
								cout << currentFight.WinnerKnightNumber << " ";
								flag = 1;
								break;
							}
						}
						else 
							priorityContainer.pop();
						
						if (priorityContainer.empty()) {
				
							for (auto item : temporaryNodeVector)
								priorityContainer.push(item);
				
							temporaryNodeVector.clear();
							cout << "0 ";
							flag = 1;
							break;
						}
					}
				}
				else {
					cout << currentFight.WinnerKnightNumber << " ";
					break;
				}
			}
			else {
				priorityContainer.pop();
				
				if (priorityContainer.empty()) {
					cout << "0 ";
					break;
				}
			}
			if (flag == 1) {
				flag = 0;
				break;
			}
		}
	}
	return 0;
}
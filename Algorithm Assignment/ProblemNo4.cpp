#include <iostream>
#include <vector>
using namespace std;

#define N 1004

vector<int> answer[N];
// Exit function
void Exit() {
    cout << "-1" << endl;
    exit(0);
}
// Structure node to maintain a list
struct node {
    int currentNodeIndex;
    node* rightSideNode;
    node* bottomSideNode;
    node* bottomNode;
};
// Function to create node
node* createNode() {
    node* temporaryNode = new node;
    temporaryNode->rightSideNode = NULL;
    temporaryNode->bottomSideNode = NULL;
    temporaryNode->bottomNode = NULL;
    return temporaryNode;
}

node* headNode = NULL;
node* currentNode = NULL;
node* previousNode = NULL;
node* newHeadNode = NULL;

int main() {
    string inputString = "0010100";
    int countOfZero = 0, countOfOne = 0;

    for(int i = 0; i < (int)inputString.size(); i++) {
        if(inputString[i] == '0')
            countOfZero++;
        else
            countOfOne++;
        // If number of zero is greate than number of ones, then exit
        if(countOfZero - countOfOne < 0)
            Exit();
    }

    if(countOfZero - countOfOne <= 0)
        Exit();

    char lastCharacter = '0';

    node* temporaryNode = NULL;
    node* bottomLastNode = NULL;

    temporaryNode = createNode();
    temporaryNode->currentNodeIndex = 0;
    headNode = currentNode = bottomLastNode = temporaryNode;
    // In next step we are creating list of nodes
    for(int i = 1; i < (int)inputString.size(); i++) {
        temporaryNode = createNode();
        temporaryNode->currentNodeIndex = i;
        if(lastCharacter == inputString[i]) {
            bottomLastNode->bottomSideNode = temporaryNode;
            bottomLastNode = temporaryNode;
        }
        else {
            currentNode->rightSideNode = temporaryNode;
            currentNode = temporaryNode;
            bottomLastNode = temporaryNode;
            lastCharacter = inputString[i];
        }
    }

    previousNode = currentNode = headNode;
    // In next step we provide a pointer to every bottom node 
    while(currentNode != NULL) {
        bottomLastNode = currentNode;
       
        while(bottomLastNode->bottomSideNode != NULL)
            bottomLastNode = bottomLastNode->bottomSideNode;
       
        currentNode->bottomNode = bottomLastNode;
        previousNode = currentNode;
        currentNode = currentNode->rightSideNode;
    }

    if(inputString[previousNode->currentNodeIndex] == '1')
        Exit();
    
    newHeadNode = currentNode = previousNode = headNode;
    int totalList = 0;
    // We are removing one list per loop from the origin string
    while(1) {
        previousNode = currentNode = newHeadNode;
    
        if(inputString[currentNode->currentNodeIndex] == '1')
            Exit();
    
        lastCharacter = 'a';
    
        while(currentNode != NULL) {
            if(lastCharacter == inputString[currentNode->currentNodeIndex])
                Exit();
    
            answer[totalList].push_back(currentNode->currentNodeIndex);
            lastCharacter = inputString[currentNode->currentNodeIndex];
            bottomLastNode = currentNode;
            bottomLastNode = bottomLastNode->bottomSideNode;
    
            if(bottomLastNode == NULL) {
                if(previousNode == currentNode) {
                    newHeadNode = currentNode->rightSideNode;
                    currentNode = currentNode->rightSideNode;
                    previousNode = currentNode;
                }
                else {
                    bottomLastNode = previousNode->bottomNode;
                    temporaryNode = currentNode->rightSideNode;
    
                    if(temporaryNode != NULL) {
                        if(temporaryNode->bottomNode == temporaryNode) {
                            if(lastCharacter == inputString[temporaryNode->currentNodeIndex])
                                Exit();
    
                            answer[totalList].push_back(temporaryNode->currentNodeIndex);
                            lastCharacter = inputString[temporaryNode->currentNodeIndex];
                            previousNode->rightSideNode = temporaryNode->rightSideNode;
                            currentNode = temporaryNode->rightSideNode;
                        }
                        else {
                            if(lastCharacter == inputString[temporaryNode->currentNodeIndex])
                                Exit();
    
                            answer[totalList].push_back(temporaryNode->currentNodeIndex);
                            lastCharacter = inputString[temporaryNode->currentNodeIndex];
                            bottomLastNode->bottomSideNode = temporaryNode->bottomSideNode;
                            previousNode->rightSideNode = temporaryNode->rightSideNode;
                            previousNode->bottomNode = temporaryNode->bottomNode;
                            currentNode = temporaryNode->rightSideNode;
                            temporaryNode->rightSideNode = NULL;
                            temporaryNode->bottomNode = NULL;
                        }
                    }
                    else {
                        previousNode->rightSideNode = NULL;
                        currentNode = NULL;
                    }
                }
            }
            else {
                if(previousNode == currentNode) {
                    newHeadNode = bottomLastNode;
                    bottomLastNode->rightSideNode = currentNode->rightSideNode;
                    bottomLastNode->bottomNode = currentNode->bottomNode;
                    currentNode = currentNode->rightSideNode;
                    previousNode = bottomLastNode;
                }
                else {
                    previousNode->rightSideNode = bottomLastNode;
                    bottomLastNode->rightSideNode = currentNode->rightSideNode;
                    bottomLastNode->bottomNode = currentNode->bottomNode;
                    previousNode = bottomLastNode;
                    currentNode = currentNode->rightSideNode;
                }
            }
        }
        totalList++;
        if(newHeadNode == NULL)
            break;
        if(inputString[previousNode->currentNodeIndex] == '1')
            Exit();
    }
    
    cout << totalList << endl;
    
    for(int j = 0; j < totalList; j++) {
        
        cout << answer[j].size() << " ";
        
        for(int k = 0; k < (int)answer[j].size(); k++)
            cout << answer[j][k] + 1 << " ";
        
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int appendToAll(string a[], int n, string value){
    if(n<0){
        return -1;
    }
    for(int i=0; i<n; i++){//wont do anything for 0
        a[i]=a[i]+value;
    }
    return n;
}

int lookup(const string a[], int n, string target){//ascii value check
    if(n<0){//negative condition
        return -1;
    }
    if(n==0){
        return 0;
    }
    for(int i=0; i<n; i++){
        if(a[i]==target){
            return i;
        }
    }
    return -1;
}


int positionOfMax(const string a[], int n){
    if(n<=0){
        return -1;
    }
    int counter=0;
    for(int i=1; i<n-1; i++){
        if(a[i]>a[counter]){//check max value of first letter. If larger replace it.
            counter=i;
        }
    }
    return counter;//returns 0 if i=0 (if n=0)
}

int rotateLeft(string a[], int n, int pos){
    if(n<=0){
        return -1;
    }
    if(pos<0||pos>=n){
        return -1;
    }
    string temp=a[pos];
    for(int i=pos; i<n-1; i++){
        a[i]=a[i+1];
    }
    a[n-1]=temp;

    return pos;
}

int countRuns(const string a[], int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 0;
    }

    int counter=1;//starts with first element
    for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) { 
            counter++;
        }
    } 
    return counter;
}

int flip(string a[], int n){
    if(n<0){
        return -1;
    }
    string temp=a[0];
    for(int i = 0; i < n / 2; i++) { 
        string temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    return n;

}

int differ(const string a1[], int n1, const string a2[], int n2){
    if(n1<0 || n2<0){
        return -1;
    }
    int counter=0;
    if(n1<n2 || n1==n2){
        for(int i=0; i<n1; i++){
            if(a1[i]!=a2[i]){
                break;
            }
            counter++;
        }
    }
    if(n1>n2){
        for(int j=0; j<n2; j++){
            if(a1[j]!=a2[j]){
                break;
            }
            counter++;
        }
    }
    return counter;
}

int subsequence(const string a1[], int n1, const string a2[], int n2){
    if(n1<0 || n2<0){
        return -1;
    }
    if((n2==0)||(n1==0 && n2==0)){
        return 0;
    }
    int counter=0;
    if(n1<n2){
            return -1;
    }
    if(n1>=n2){
        for(int i=0; i<n1; i++){
             if(a1[i]==a2[0]){
                for(int j=0; j<n2; j++){
                    if(a1[i]!=a2[j]){
                        return counter;
                    }
                
                }
            }
            else{
                if(i>n2)
                    return -1;
            }
            counter++;
        }
    }
    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2){
    if(n1<=0 || n2<=0){
        return -1;
    }
    if(n1==0 && n2==0){
        return -1;
    }
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(a1[i]==a2[j]){
                return i;
            }

        }

    }
    return -1;
}

int separate(string a[], int n, string separator) { 
    if (n < 0) { 
        return -1; 
    } 
    int left = 0; int right = n - 1;
    while (left <= right) { 
    // Move left index to the right until we find an element >= separator 
        while (left < n && a[left] < separator) { 
            left++; 
        } 
        // Move right index to the left until we find an element < separator 
        while (right >= 0 && a[right] >= separator) { 
            right--; 
        } 
        // Swaping elements 
        if (left < right) { 
            string tempvalue=a[left];//setting a temp value for switching elements
            a[left]= a[right];
            a[right]=tempvalue;

            left++;
            right--;
            }
    } 

    // Find the position of the first element >= separator 
    for (int i = 0; i < n; i++){ 
        if (a[i] >= separator){ 
            return i;
        }
    }
    return n;
}


int main(){
//test case data
/*
    string d[5] = { "kirana", "kirana", "kirana", "tim", "tim" };
    string e[4] = { "donald", "tim", "", "doug" };
    string f[3] = { "jd", "donald", "gwen" };
    string g[4] = { "melania", "kirana", "jd", "usha" };
    string h[7] = { "melania", "kirana", "donald", "tim", "", "doug", "jd" };
    string i[4] = { "tim", "Tim", "tIM", "tiM" };
    string j[4] = { "1tim", "Tim", "tIM", "TIM" };
    string k[4] = { "1", "2", "a", "b" };
    string m[7] = { "melania", "kirana", "donald", "tim", "", "doug", "jd" };
    string people[6] = { "doug", "kirana", "melania", "usha", "gwen", "donald" };
    string people2[4] = { "jill", "tim", "jd", "joe" };
    string a[] = {"apples", "banana", "cherry"}; 
    assert(appendToAll(a, 3, "s") == 3); 
    assert(a[0] == "appless" && a[1] == "bananas" && a[2] == "cherrys");
    string b[] = {"dog", "cat", "mouse"};
    assert(appendToAll(b, 3, "es") == 3);
    assert(b[0] == "doges" && b[1] == "cates" && b[2] == "mousees");
    assert(appendToAll(a, -1, "test") == -1);
    assert(appendToAll(m, 7, "l")==7);
    assert(m[0]=="melanial" && m[1]=="kiranal" && m[2]=="donaldl"&& m[3]=="timl"&& m[4]=="l"&& m[5]=="dougl"&& m[6]== "jdl" );
    assert(appendToAll(m, 0, "")==0);

    string l[] = {"apples", "banana", "cherry"};
    assert(lookup(l, 3, "banana") == 1);
    assert(lookup(l, 3, "cherry") == 2);
    assert(lookup(l, 3, "date") == -1);
    assert(lookup(l, -1, "apples") == -1);
    assert(lookup(h, 7, "doug") == 5);
    assert(lookup(h, 7, "donald") == 2);
    assert(lookup(h, 2, "donald") == -1);
    assert(lookup(h, 0, "donald")==0);

    string v[] = {"dog", "cat", "mouse"}; 
    assert(rotateLeft(v, 3, 0) == 0); 
    assert(v[0] == "cat" && v[1] == "mouse" && v[2] == "dog"); 
    assert(rotateLeft(a, -1, 1) == -1);

    string p[] = {"apples", "apples", "banana", "banana", "cherry"}; 
    assert(countRuns(p, 5) == 3); 
    string D[] = {"dog", "dog", "dog"}; 
    assert(countRuns(D, 3) == 1); 
    assert(countRuns(p, -1) == -1);
    
    string q[9] = {"melania", "doug", "gwen", "gwen", "jill", "jill", "jill", "gwen", "gwen"};
    assert(countRuns(q, 9)==5);
    assert(positionOfMax(h, 7)==3);
    string s[4]={"alpha", "Zeta", "varge", "poppy"};
    assert(positionOfMax(s, 4)==2);//Z is technically less than v

    assert(differ(h, 4, g, 4) == 2);
    assert(differ(h, 4, s, 4)==0);
    assert(differ(h, 4, h, 4)==4);

    assert(appendToAll(g, 4, "?") == 4 && g[0] == "melania?" && g[3] == "usha?");


    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "jd?" && g[3] == "kirana?");


    assert(subsequence(h, 7, e, 4) == 2);

//add more test cases for if it is the second one or third. Or only the first. Only the last etc.
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(lookupAny(h, 7, a, 3)==-1);//look for none in string


    assert(separate(people, 6, "joe")==3);
    assert(separate(h, 7, "doug") == 2);
    assert(separate(people2, 4, "joe")==2); //returns 2
    string people3[11]={"pooja", "frank", "louis", "conor", "Lincoln", "obama", "ZED", "zed", "LIP", "virginia", "NULL"};
    assert(separate(people3, 11, "zed")==10);//should ZED be larger than zed???

    assert(countRuns(d,0)==0);
    assert(countRuns(d, 5) == 2);
    assert(countRuns(d, 1)==1);
    assert(flip(f, 3) == 3 && f[0] == "gwen" && f[2] == "jd");

    string X[2] = {"dog", "cat"};
    assert(flip(X, 2) == 2); 
    assert(X[0] == "cat" && X[1] == "dog");
    assert(flip(X, -1) == -1);


    assert(rotateLeft(a, 3, 1) == 1);
    assert(a[0]=="appless" && a[1]=="cherrys" && a[2]=="bananas");

    assert(a[0] == "appless" && a[1] == "cherrys" && a[2] == "bananas");

    assert(flip(a, 3) == 3);

    assert(a[0] == "bananas" && a[1] == "cherrys" && a[2] == "appless");
    assert(rotateLeft(a, -2, 1) == -1);
    assert(differ(d,0,a,0)==0);
    assert(appendToAll(d,2,"s")==2);
    assert(d[0]=="kiranas"&& d[1]=="kiranas");

    cout<<"All tests succeeded"<<endl;
*/
    return 0;
}

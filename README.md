# SimpleArrayFunctions
Simple everyday functions / code snippets for arrays:

  appendToAll: adds a character to all elements of the array
  lookup: simple array lookup for a specific character
  positionOfMax: returns position of highest ascii value character
  rotateLeft: rotates the array to the left by one element. Replaces the last element with the first one.
  countRuns: gives the number of unique parts of the array when they are grouped or counts the runs (1 is a valid run)
  flip: reverses array
  differ: returns the first index where two arrays differ
  subsequence: checks if the first array holds the second array as a subsequence. It treats an empty array as a subset of all arrays.
  lookUpAny: checks if there exists an element equal in the second array to the first array
  seperate: alphabetically sorts the array


  test data:







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
    

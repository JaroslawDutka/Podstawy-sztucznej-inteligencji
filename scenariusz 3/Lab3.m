close all; clear all; clc;

PR=[0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1;   
    0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1;
     0 1; 0 1; 0 1; 0 1];
%wejscia do sieci i min/max wartosci wejsc


net = newff(PR,[24 20],{'tansig' 'logsig'},'traingda'); 


   %A a B b C c D d E e Z z R r K k H h L l
WE=[0 0 1 1 1 0 1 0 1 0 1 0 1 0 1 1 1 1 1 1 ;
    1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 ;
    1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 ;
    0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 ;
    1 0 1 1 1 0 1 0 1 1 0 0 1 0 1 1 1 1 1 1 ;
    0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 ;
    0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 ;
    1 0 1 0 0 0 1 1 0 0 1 0 1 0 0 0 1 0 0 0 ;
    1 0 1 1 1 1 1 0 1 1 0 1 1 0 1 1 1 1 1 1 ;
    0 1 1 1 0 1 0 1 1 0 0 1 1 1 1 0 1 0 0 0 ;
    0 0 1 1 0 1 0 1 1 0 1 1 1 1 0 1 1 0 0 0 ;
    1 0 0 0 0 0 1 1 1 1 0 1 0 1 0 0 1 0 0 0 ;
    1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 ;
    1 0 0 0 0 0 0 0 0 1 1 0 0 0 1 1 0 1 0 0 ;
    1 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0 0 ;
    1 0 1 1 0 0 1 1 0 0 0 0 1 0 0 0 1 0 0 0 ;
    1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 ;
    0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 ;
    0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 ;
    1 0 1 1 0 0 1 1 0 0 0 0 1 0 0 0 1 1 0 0 ;
     1 0 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 ;
     0 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 1 0 ;
     0 0 1 1 1 1 1 1 1 1 1 1 0 0 0 1 0 0 1 0 ;
     1 1 0 0 1 0 0 1 1 1 1 1 1 0 1 0 1 1 1 0 ;
    ];
  
   %A a B b C c D d E e Z z R r K k H h L l
WY=[1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; %A
    0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; %a
    0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; %B
    0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; %b
    0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; %C
    0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0; %c
    0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0; %D
    0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0; %d
    0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0; %E
    0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0; %e
    0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0; %Z
    0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0; %z
    0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0; %R
    0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0; %r
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0; %K
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0; %k
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0; %H
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0; %h
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0; %L
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1]; %l

net.name='Rozpoznawanie liter';

%parametry treningu
net.trainParam.epochs = 4000; %max iloœæ epok
net.trainParam.mu = 0.001; %wspó³czynnik uczenia

net = train(net, WE, WY);%uczenie

%litery do testu: 
testA = [0; 1; 1; 0; 
         1; 0; 0; 1; 
         1; 0; 0; 1; 
         1; 1; 1; 1;
         1; 0; 0; 1;
         1; 0; 0; 1]; %A
testa = [0; 0; 0; 0; 
         0; 0; 0; 0;
         0; 1; 0; 0;
         1; 0; 1; 0;
         1; 0; 1; 0; 
         0; 1; 0; 1]; %a
testB = [1; 1; 1; 0;
         1; 0; 0; 1;
         1; 1; 1; 0;
         1; 0; 0; 1;
         1; 0; 0; 1; 
         1; 1; 1; 0	]; %B
testb = [1; 0; 0; 0; 
         1; 0; 0; 0; 
         1; 1; 1; 0; 
         1; 0; 0; 1;
         1; 0; 0; 1; 
         1; 1; 1; 0]; %b
testC = [1; 1; 1; 1;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 1; 1; 1]; %C
testc = [0; 0; 0; 0;
         0; 0; 0; 0; 
         1; 1; 1; 0; 
         1; 0; 0; 0;
         1; 0; 0; 0; 
         1; 1; 1; 0]; %c
testD = [1; 1; 1; 0; 
         1; 0; 0; 1;
         1; 0; 0; 1;
         1; 0; 0; 1;
         1; 0; 0; 1;
         1; 1; 1; 0]; %D
testd = [0; 0; 0; 1;
         0; 0; 0; 1;
         0; 1; 1; 1; 
         1; 0; 0; 1;
         1; 0; 0; 1;
         0; 1; 1; 1];%d
testE = [1; 1; 1; 1;
         1; 0; 0; 0;
         1; 1; 1; 1;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 1; 1; 1];%E
teste = [0; 0; 0; 0;
         1; 1; 1; 0;
         1; 0; 0; 1;
         1; 1; 1; 0;
         1; 0; 0; 0; 
         1; 1; 1; 1];%e
testZ = [1; 1; 1; 1;
         0; 0; 0; 1;
         0; 0; 1; 0; 
         0; 1; 0; 0;
         1; 0; 0; 0; 
         1; 1; 1; 1]; %Z
testz = [0; 0; 0; 0;
         0; 0; 0; 0; 
         1; 1; 1; 1;
         1; 0; 1; 0; 
         0; 1; 0; 0; 
         1; 1; 1; 1]; %z
testR = [1; 1; 1; 0;
         1; 0; 0; 1;
         1; 1; 1; 0;
         1; 0; 0; 1;
         1; 0; 0; 1;
         1; 0; 0; 1];    %R 
testr = [0; 0; 0; 0;
         0; 0; 0; 0;
         0; 1; 1; 1;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0];      %r
testK = [1; 0; 0; 1;
         1; 0; 1; 0;
         1; 1; 0; 0;
         1; 1; 0; 0;
         1; 0; 1; 0;
         1; 0; 0; 1];     %K
testk = [1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 1; 0;
         1; 1; 0; 0;
         1; 1; 0; 0;
         1; 0; 1; 0];      %k
testH = [1; 0; 0; 1;
         1; 0; 0; 1;
         1; 1; 1; 1; 
         1; 0; 0; 1;
         1; 0; 0; 1;
         1; 0; 0; 1]; %H
testh = [1; 0; 0; 0; 
         1; 0; 0; 0; 
         1; 0; 0; 0; 
         1; 1; 1; 0; 
         1; 0; 0; 1;
         1; 0; 0; 1]; %h
testL = [1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 1; 1; 1]; %L     
testl = [1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0;
         1; 0; 0; 0]; %l     
     
     
wynik=sim(net, testa);%testowanie sieci
%testX gdzie x to litera

%szukanie najwiekszej wartosci
max=1;
for i=1:1:20
    if (wynik(max)<wynik(i))
        max=i;
    end;
end


%wypisywanie wartosci dla poszczegolnych liter
disp('Wartosci wyjsciowe algorytmu dla wszystkich liter:')
disp('A='),disp(wynik(1));
disp('a='),disp(wynik(2));
disp('B='),disp(wynik(3));
disp('b='),disp(wynik(4));
disp('C='),disp(wynik(5));
disp('c='),disp(wynik(6));
disp('D='),disp(wynik(7));
disp('d='),disp(wynik(8));
disp('E='),disp(wynik(9));
disp('e='),disp(wynik(10));
disp('Z='),disp(wynik(11));
disp('z='),disp(wynik(12));
disp('R='),disp(wynik(13));
disp('r='),disp(wynik(14));
disp('K='),disp(wynik(15));
disp('k='),disp(wynik(16));
disp('H='),disp(wynik(17));
disp('h='),disp(wynik(18));
disp('L='),disp(wynik(19));
disp('l='),disp(wynik(20));

%wypisywanie jaka to litera
switch max
    case 1
        disp('Wpisana litera to A')
    case 2
        disp('Wpisana litera to a')
    case 3
        disp('Wpisana litera to B')
    case 4
        disp('Wpisana litera to b')
    case 5
        disp('Wpisana litera to C')
    case 6
        disp('Wpisana litera to c')
    case 7
        disp('Wpisana litera to D')
    case 8
        disp('Wpisana litera to d')
    case 9
        disp('Wpisana litera to E')
    case 10
        disp('Wpisana litera to e')
    case 11
        disp('Wpisana litera to Z')
    case 12
        disp('Wpisana litera to z')
    case 13
        disp('Wpisana litera to R')
    case 14
        disp('Wpisana litera to r')
    case 15
        disp('Wpisana litera to K')
    case 16
        disp('Wpisana litera to k')
    case 17
        disp('Wpisana litera to H')
    case 18
        disp('Wpisana litera to h')
    case 19
        disp('Wpisana litera to L')
    case 20
        disp('Wpisana litera to l')
    otherwise
        disp('Blad dzialania programu')
end

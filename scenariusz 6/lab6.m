close all; clear all; clc;

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
 
 

% SOM parametry
wymiary   = [3,3];
coverSteps   = 100;
initNeighbor = 1;
topologyFcn  = 'hextop';
distanceFcn  = 'linkdist';

% Tworzenie SOM
net = selforgmap(wymiary,coverSteps,initNeighbor,topologyFcn,distanceFcn);
net.trainParam.epochs = 200;
net.trainFcn = 'trainbu';

% Trenowanie sieci
[net,tr] = train(net,WE);

 

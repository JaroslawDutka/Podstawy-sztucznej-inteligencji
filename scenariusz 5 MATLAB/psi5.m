%wczytanie danych testowych do zmiennej z pliku tekstowego
I = load('dane.txt');
I = I';
I1 = load('dane.txt');
I2 = load('dane1.txt'); 
%normalizacja danych
inputs = (I-min(I(:))) ./ (max(I(:) - min(I(:))));

%Tworzenie sieci Kohonena o wymiarach [dl x sz]
net = selforgmap([20 20]);
%Trening sieci
[net, tr] = train(net, inputs);

outputs = net(inputs);
nidx = vec2ind(outputs)';

a = net.IW{:,:};
save kohonennidx.txt nidx -ascii -double

save kohonenweights.txt a -ascii -double
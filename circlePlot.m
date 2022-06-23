fileID1 = fopen('output.txt','r');
formatSpec1 = '%f';
A = fscanf(fileID1,formatSpec1);

B=load('data.txt');
plot(B(:,1),B(:,2))

radius = A(1);
x_cor = A(2);
y_cor = A(3);
th = linspace(0,2*pi) ; 
R = radius ;  % Radius 
C = [x_cor y_cor] ; % center 
x = C(1)+R*cos(th) ; 
y = C(2)+R*sin(th) ;
plot(x,y)
hold on
plot(x_cor,y_cor,'o-','MarkerFaceColor','blue','MarkerEdgeColor','red')

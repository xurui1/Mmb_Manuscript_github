% Program IsoSurface, run by typing run("./main.m") in Matlab capable enviroment
% Clear all previous variables
clear all;
% Getting the coordiante variables from the data, and making them
% into the correct format, mesh
A=importdata('./xyz.dat');
%getting the concentration from the data file
B=importdata('./ABCD.dat');

[X,Y,Z]=meshgrid(A(:,1),A(:,2),A(:,3));
[X,Y,Z] = pol2cart(X,Y,Z);

% The size is used for the for loop
x_size=size(A(:,1),1);
y_size=size(A(:,2),1);
z_size=size(A(:,3),1);

% Dividing up the concentration values
VA=zeros(x_size,y_size,z_size);
VB=zeros(x_size,y_size,z_size);
VC=zeros(x_size,y_size,z_size);

% Taking the concentration values and putting them into the correct
% format, mesh-format
ii=1;
for i=1:x_size,
    for j=1:y_size,
        for k=1:z_size,
            VA(i,j,k)=B(ii,4);
            VB(i,j,k)=B(ii,5);
            VC(i,j,k)=B(ii,6);
            ii=ii+1;
        end
    end
end
% clearing useless variables
clear i;
clear j;
clear k;
clear ii;
% Thres3old for the isosurf, 
cutA=0.5;
cutB=0.5;
cutC=0.5;


axis vis3d;
view([1.0,-2.5,1.5]);
axis off;
daspect('mode');

camlight
lighting gouraud


% A    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pA = patch(isosurface(X,Y,Z,VA,cutA),'FaceColor','red','EdgeColor','none');
qA = patch(isocaps(X,Y,Z,VA,cutA),'FaceColor','red','EdgeColor', ...
         'none');
alpha(pA,0.6);
alpha(qA,0.6);

% B
% ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pB = patch(isosurface(X,Y,Z,VB,cutB),'FaceColor','green','EdgeColor','none');
qB = patch(isocaps(X,Y,Z,VB,cutB),'FaceColor','green','EdgeColor', ...
          'none');
alpha(pB,0.6);
alpha(qB,0.6);

% C
% ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pC = patch(isosurface(X,Y,Z,VC,cutC),'FaceColor','blue','EdgeColor','none');
qC = patch(isocaps(X,Y,Z,VC,cutC),'FaceColor','blue','EdgeColor', ...
           'none');
alpha(pC,0.2);
alpha(qC,0.2);

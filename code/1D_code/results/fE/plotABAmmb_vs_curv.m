clear all;
counter = 1;

for k = 0: 1: 50
     
    
    % Create a mat filename, and load it into a structure called matData.
    
   
        matFileName = sprintf('./ABA/ABA_sph_%d.dat', k);
    
    
	if exist(matFileName, 'file')
		matData = load(matFileName);
        data(counter).rad = matData(:,1);
		
        data(counter).phiA1 = matData(:,2);
        data(counter).phiB1 = matData(:,3);
        data(counter).phiA2 = matData(:,4);
        data(counter).phiB2 = matData(:,5);
        data(counter).phiA3 = matData(:,6);
        data(counter).phiC = matData(:,7);
        
        %total hydrophilic component
        data(counter).phiA = data(counter).phiA1 + data(counter).phiA2 + data(counter).phiA3;
        
        %total hydrophobic component
        data(counter).phiB = data(counter).phiB1 + data(counter).phiB2;
	else
		fprintf('File %s does not exist.\n', matFileName);
    end
    
    counter=counter+1;
end

for t=50:-1:1
     
    plot(data(t).rad, data(t).phiA, 'r-',data(t).rad, data(t).phiB, 'b-',data(t).rad, data(t).phiC, 'k-' );
    ylim([0 1]);
    xlim([data(t).rad(1) data(t).rad(1)+12]);
 %   %grid on;
 
    xlabel('Radius (r /R_g )');
    ylabel('Concentration (\phi  )');
    legend('\phi_A','\phi_B', '\phi_C','Location','east' );
    set(gca,'fontsize',18)

    % gif utilities
    set(gcf,'color','w'); % set figure background to white
    drawnow;
    frame = getframe(1);
    im = frame2im(frame);
    [imind,cm] = rgb2ind(im,256);
    outfile = 'ABAsph_phi.gif';
 
    % On the first loop, create the file. In subsequent loops, append.
    if t==50
        imwrite(imind,cm,outfile,'gif','DelayTime',0,'loopcount',inf);
    else
        imwrite(imind,cm,outfile,'gif','DelayTime',0,'writemode','append');
    end
 
end

for t = 1:50
    
    ylim([0 1]);
 
    plot(data(t).rad, data(t).phiA, 'r-',data(t).rad, data(t).phiB, 'b-',data(t).rad, data(t).phiC, 'k-' );
    xlim([data(t).rad(1) data(t).rad(1)+12]);
 %   %grid on;
 
    xlabel('Radius (r /R_g )');
    ylabel('Concentration (\phi  )');
    legend('\phi_A','\phi_B', '\phi_C','Location','east' );
    set(gca,'fontsize',18)

    % gif utilities
    set(gcf,'color','w'); % set figure background to white
    drawnow;
    frame = getframe(1);
    im = frame2im(frame);
    [imind,cm] = rgb2ind(im,256);
    outfile = 'ABAsph_phi.gif';
    imwrite(imind,cm,outfile,'gif','DelayTime',0,'writemode','append');
    
end

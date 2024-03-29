if(exist('NOSIMULIS'))
    clear NOSIMULIS
end
%     NOSIMULIS=1;

if (not(exist('NOSIMULIS')))
    clear;
    parametres
    
    tic
        sim modelSPSid0
    toc
    
    preparadades
end

if(exist('NOGRAFIQUIS'))
    clear NOGRAFIQUIS
end
 %NOGRAFIQUIS=1;

if (not(exist('NOGRAFIQUIS')))
        t0=min(captura.t);
        t1=max(captura.t);
    
    if(exist('FILTRA'))
        clear FILTRA
    end
    FILTRA=1;

    if(exist('FILTRA'))
        %Passabaixos a freq. molt baixa
        [z,p,k]=ellip(6,0.2,50,1*parControl.Electric.Generador.T*2);
        FVVLP=zpk(z,p,k,parControl.Electric.Generador.T*2);
        [z,p,k]=ellip(6,0.2,50,10*parControl.Electric.Generador.T*2);
        FVLP=zpk(z,p,k,parControl.Electric.Generador.T*2);
        [z,p,k]=ellip(6,0.2,50,80*parControl.Electric.Generador.T*2);
        FLP=zpk(z,p,k,parControl.Electric.Generador.T*2);
        clear z p k
    end
    
    close all

    figure('Position',[150 300 640 480],'Name','Control de velocitat');
    subplot(2,1,1);
    graficamela({captura.t,captura.t},{captura.Generador.parell_m,captura.Control.Mecanic.parell_ma},{},{'Temps [s]','Parell [Nm]'},{'Parell obtingut','Parell consignat'},[t0 t1 inf inf 0.1]);
    subplot(2,1,2);
    graficamela({captura.t},{captura.Generador.omega_m*30/pi},{},{'Temps [s]','Velocitat [min^{-1}]'},{},[t0 t1 inf inf 0.1]);

    figure('Position',[150 300 640 480],'Name','Amplitud de les tensions d estator');
    if(exist('FILTRA'))
        graficamela({captura.t,captura.t,captura.t},{lsim(FVLP,sqrt(captura.Generador.vsqd(:,1).^2+captura.Generador.vsqd(:,2).^2)),lsim(FVLP,sqrt(captura.Control.Electric.Generador.vscqd(:,1).^2+captura.Control.Electric.Generador.vscqd(:,2).^2)),lsim(FVLP,captura.Generador.omega_m*parGenerador.lambda_m*parGenerador.P)},{'b','g','r'},{'Temps [s]','Tensio [V]'},{'Tensio estator (filtrada)','Tensio estator control (filtrada)','Tensio generada imant (filtrada)'},[t0,t1 inf inf, 0.1]);
    else
        graficamela({captura.t,captura.t,captura.t},{sqrt(captura.Control.Electric.Generador.vscqd(:,1).^2+captura.Control.Electric.Generador.vscqd(:,2).^2),sqrt(captura.Generador.vsqd(:,1).^2+captura.Generador.vsqd(:,2).^2),captura.Generador.omega_m*parGenerador.lambda_m*parGenerador.P},{'b--','b','r'},{'Temps [s]','Tensio [V]'},{'Tensio estator control','Tensio estator aplicada','Tensio generada imant'},[t0,t1 inf inf, 0.1]);
    end
    
    figure('Position',[150 300 640 480],'Name','Control de components de corrent d estator');
    subplot(2,1,1);
    graficamela({captura.t,captura.t},{captura.Control.Electric.Generador.isqda(:,1),captura.Control.Electric.Generador.isqd(:,1)},{'r','g'},{'Temps [s]','Corrent [A]'},{'i_{sq}^*','i_{sq}'},[t0,t1 inf inf, 0.1]);
    subplot(2,1,2);
    graficamela({captura.t,captura.t},{captura.Control.Electric.Generador.isqda(:,2),captura.Control.Electric.Generador.isqd(:,2)},{'r','g'},{'Temps [s]','Corrent [A]'},{'i_{sd}^*','i_{sd}'},[t0,t1 inf inf, 0.1]);
    
%     figure('Position',[150 300 640 480],'Name','Tensio del Bus de Continua');
%     subplot(2,1,1);
%     graficamela({captura.t,captura.t},{captura.BusContinua.E,captura.Control.Electric.BusContinua.Ea},{},{'Temps [s]','Tensio [V]'},{'E','E^*'},[t0 t1 inf inf, 0.1]);
%     subplot(2,1,2);
%     graficamela({captura.t,captura.t,captura.t},{captura.BusContinua.iDCm,captura.BusContinua.iDCl,captura.Control.Electric.BusContinua.iDCla},{'r','g','g--'},{'Temps [s]','Corrent [A]'},{'i_{DCm}','i_{DCl}','i_{DCl}^*'},[t0 t1 inf inf, 0.1]);
%%
HIDEZEROSEQ=1;
    figure('Position',[150 300 640 480],'Name','Tensions i corrents d estator');
    subplot(2,1,1);
    if(exist('FILTRA'))
        graficamela({captura.t,captura.t,captura.t,captura.t,captura.t,captura.t},{lsim(FLP,captura.Generador.vsabc(:,1)-HIDEZEROSEQ*(captura.Generador.vsabc(:,1)+captura.Generador.vsabc(:,2)+captura.Generador.vsabc(:,3))/3),lsim(FLP,captura.Generador.vsabc(:,2)-HIDEZEROSEQ*(captura.Generador.vsabc(:,1)+captura.Generador.vsabc(:,2)+captura.Generador.vsabc(:,3))/3),lsim(FLP,captura.Generador.vsabc(:,3)-HIDEZEROSEQ*(captura.Generador.vsabc(:,1)+captura.Generador.vsabc(:,2)+captura.Generador.vsabc(:,3))/3),...
            lsim(FLP,captura.Control.Electric.Generador.vscabc(:,1)-HIDEZEROSEQ*(captura.Control.Electric.Generador.vscabc(:,1)+captura.Control.Electric.Generador.vscabc(:,2)+captura.Control.Electric.Generador.vscabc(:,3))/3),lsim(FLP,captura.Control.Electric.Generador.vscabc(:,2)-HIDEZEROSEQ*(captura.Control.Electric.Generador.vscabc(:,1)+captura.Control.Electric.Generador.vscabc(:,2)+captura.Control.Electric.Generador.vscabc(:,3))/3),lsim(FLP,captura.Control.Electric.Generador.vscabc(:,3)-HIDEZEROSEQ*(captura.Control.Electric.Generador.vscabc(:,1)+captura.Control.Electric.Generador.vscabc(:,2)+captura.Control.Electric.Generador.vscabc(:,3))/3)},{'r','g','b','r--','g--','b--'},{'Temps [s]','Tensio [V]'},{},[t0,t1 inf inf, 0.1]);
    else
        graficamela({captura.t,captura.t,captura.t},{captura.Generador.vsabc(:,1),captura.Generador.vsabc(:,2),captura.Generador.vsabc(:,3)},{'r','g','b'},{'Temps [s]','Tensio [V]'},{},[t0,t1 inf inf, 0.1]);
    end
    subplot(2,1,2);
    graficamela({captura.t,captura.t,captura.t},{captura.Generador.isabc(:,1),captura.Generador.isabc(:,2),captura.Generador.isabc(:,3)},{'r','g','b'},{'Temps [s]','Intensitat [A]'},{},[t0,t1 inf inf, 0.1]);
      %%  
    figure('Position',[150 300 640 480],'Name','Potencia activa');
    subplot(2,1,1);
    if(exist('FILTRA'))
        graficamela({captura.t,captura.t,captura.t},{lsim(FVLP,captura.Generador.isabc(:,1).*captura.Generador.vsabc(:,1)+captura.Generador.isabc(:,2).*captura.Generador.vsabc(:,2)+captura.Generador.isabc(:,3).*captura.Generador.vsabc(:,3)), lsim(FVLP,captura.BusContinua.E.*captura.BusContinua.iDCm), captura.Generador.parell_m.*captura.Generador.omega_m},{'b','g','r'},{'Temps [s]','Potencia [W]'},{'Potencia estator (filtrada)','Potencia Bus DC (filtrada)','Potencia Mecanica'},[t0,t1 inf inf, 0.1]);  
    else
        graficamela({captura.t},{captura.Generador.isabc(:,1).*captura.Generador.vsabc(:,1)+captura.Generador.isabc(:,2).*captura.Generador.vsabc(:,2)+captura.Generador.isabc(:,3).*captura.Generador.vsabc(:,3),captura.BusContinua.E.*captura.BusContinua.iDCm, captura.Generador.parell_m.*captura.Generador.omega_m},{'b','g','r'},{'Temps [s]','Potencia [W]'},{'Potencia estator','Potencia Bus DC','Potencia Mecanica'},[t0,t1 inf inf, 0.1]);  
    end
     subplot(2,1,2);
     if(exist('FILTRA'))
         graficamela({captura.t},{((lsim(FVVLP,captura.BusContinua.E.*captura.BusContinua.iDCm))./lsim(FVVLP,(captura.Generador.parell_m.*captura.Generador.omega_m)))*100},{'b'},{'Temps [s]','Rendiment [%]'},{},[t0,t1 50 105, 0.1]);  
     else
         graficamela({captura.t},{(captura.BusContinua.E.*captura.BusContinua.iDCm*100)./(captura.Generador.parell_m.*captura.Generador.omega_m)},{'b'},{'Temps [s]','Rendiment [%]'},{},[t0,t1 50 105, 0.1]);  
     end
    
figure('Position',[150 300 640 480],'Name','Rendiments');
%     subplot(1,1,1);
    if(exist('FILTRA'))
        graficamela({captura.t},{(lsim(FVVLP,captura.Generador.isabc(:,1).*captura.Generador.vsabc(:,1)+captura.Generador.isabc(:,2).*captura.Generador.vsabc(:,2)+captura.Generador.isabc(:,3).*captura.Generador.vsabc(:,3))./lsim(FVVLP,captura.Generador.parell_m.*captura.Generador.omega_m))*100},{'b','g','r'},{'Temps [s]','Rendiment Est�tor [%]'},{'Rendiment Est�tor Isd=0','Rendiment Est�tor Qs=0','Rendimemt Pont de diodes'},[t0,t1 80 100, 0.1]);  

    else
        graficamela({captura.t},{((captura.Generador.isabc(:,1).*captura.Generador.vsabc(:,1)+captura.Generador.isabc(:,2).*captura.Generador.vsabc(:,2)+captura.Generador.isabc(:,3).*captura.Generador.vsabc(:,3))./(captura.Generador.parell_m.*captura.Generador.omega_m))*100},{'b','g','r'},{'Temps [s]','Rendiment Est�tor [%]'},{'Rendiment Est�tor Isd=0','Rendiment Est�tor Qs=0','Rendimemt Pont de diodes'},[t0,t1 -100 100, 0.1]);  
    end

end

if (exist('NOSIMULIS')) clear NOSIMULIS; end
if (exist('NOGRAFIQUIS')) clear GRAFIQUIS; end
if (exist('FILTRA')) clear FILTRA FVVLP FVLP FLP; end
clear t0 
clear t1;
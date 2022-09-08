parSimulacio.ti=0;
parSimulacio.tf=0.1;
parSimulacio.tol=1e-4;
parSimulacio.pas=1/(20*20e3);
parSimulacio.captura.Tmostreig=1/(20*20e3);
parSimulacio.captura.Delmat=1;

parGenerador.rs=50e-3;
parGenerador.Lq=0.35e-3;
parGenerador.Ld=0.35e-3;
parGenerador.lambda_m=0.2;
parGenerador.P=4;
parGenerador.isqd0=[0;0];

parControl.Electric.Generador.rs=parGenerador.rs;
parControl.Electric.Generador.Lq=parGenerador.Lq;
parControl.Electric.Generador.Ld=parGenerador.Ld;
parControl.Electric.Generador.lambda_m=parGenerador.lambda_m;
parControl.Electric.Generador.P=parGenerador.P;
parControl.Electric.Generador.qalpha=5e2;
parControl.Electric.Generador.dalpha=parControl.Electric.Generador.qalpha;
parControl.Electric.Generador.T=1/20e3;
parControl.Electric.Generador.qKp=5e2*parControl.Electric.Generador.rs*parControl.Electric.Generador.T/2*((1+exp(-parControl.Electric.Generador.rs/parControl.Electric.Generador.Lq*parControl.Electric.Generador.T))/(1-exp(-parControl.Electric.Generador.rs/parControl.Electric.Generador.Lq*parControl.Electric.Generador.T)));
parControl.Electric.Generador.qKi=5e2*parControl.Electric.Generador.rs;
parControl.Electric.Generador.dKp=5e2*parControl.Electric.Generador.rs*parControl.Electric.Generador.T/2*((1+exp(-parControl.Electric.Generador.rs/parControl.Electric.Generador.Ld*parControl.Electric.Generador.T))/(1-exp(-parControl.Electric.Generador.rs/parControl.Electric.Generador.Ld*parControl.Electric.Generador.T)));
parControl.Electric.Generador.dKi=5e2*parControl.Electric.Generador.rs;
parControl.Electric.Generador.qGcnum=[(parControl.Electric.Generador.qKi*1/20e3+2*parControl.Electric.Generador.qKp)/2, (parControl.Electric.Generador.qKi*parControl.Electric.Generador.T-2*parControl.Electric.Generador.qKp)/2];
parControl.Electric.Generador.qGcden=[1 -1];
parControl.Electric.Generador.dGcnum=[(parControl.Electric.Generador.dKi*parControl.Electric.Generador.T+2*parControl.Electric.Generador.dKp)/2, (parControl.Electric.Generador.dKi*parControl.Electric.Generador.T-2*parControl.Electric.Generador.dKp)/2];
parControl.Electric.Generador.dGcden=[1 -1];
parControl.Electric.Generador.SVPWM.T=parControl.Electric.Generador.T;
parControl.Electric.Generador.SVPWM.resolucio=64;
parControl.Electric.Generador.PWM.T=parControl.Electric.Generador.T;
parControl.Electric.Generador.PWM.resolucio=64;

parConvertidor.C=10e-2;
parConvertidor.E0=80;

parMecanica.omegat0=2000*pi/180;
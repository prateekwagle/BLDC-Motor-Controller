function handmela=graficamela(x,y,stils,llabels,llegenda,rangs,tipus)
% handmela=graficamela(x,y,stils,labels,llegenda,rangs,tipus)
% 
% Fa un plot de les variables y respecte les x. Les variables stils,
% labels,llegenda i rangs son opcionals i permeten especificar estils 
% de linea, llegenda i rangs de les variables.
% 
% Retorna els handlers de les grafiques per si s'hi vol fer alguna cosa.
% 
% x,y 
% es passen en forma d'estructura: {x1,x2,x3},{y1,y2,y3}
%
% stils 
% es una estructura amb l'estil de cada corba: {'r','g','k--'}
%
% labels
% el nom de l'eix X i Y en una estructura: {'Temps [s]','Tensio [1]'}
%
% llegenda
% es una estructura amb les cadenes de text de la llegenda, si una
% corba no ha d'apareixer a la llegenda, es posa un zero en comptes d'una
% cadena de text i no apareix: {'Grafica 1',0,'Grafica 2'}
% 
% rangs
% es un vector amb el rang de les x, el rang de les ys i el marge en tant
% per u que s'ha de deixar a l'escala de la grafica (p.e. 0.1). Si un element es
% desconeix, es pot posar inf i el programa busca ell solet el rang:
% [0,40,inf,inf,0.1]
% 
% tipus
% permet fer grafics logaritmics del tipus semilogx,semilogy o loglog.
% S'especifica passant el tipus com a cadena de text:
% 'semilogx'
%
% Exemple 1:
% x1=0:0.01:2*pi;
% x2=1:0.01:2*pi;
% y1=sin(x1);
% y2=sin(x2)*2;
% graficamela({x1,x2,[-5000,5000]},{y1,y2,[0,0]},{'r','g','k'},{},{'Sin x','2 Sin x',0},[inf inf, -3, 5,0])
% 
% Exemple2:
% x1=0:0.01:2*pi;
% x2=1:0.01:2*pi;
% y1=sin(x1);
% y2=sin(x2)*2;
% graficamela({x1,x2,[-5000,5000]},{y1,y2,[0,0]},{},{'Temps [s]','Tensio
% [1]'},{'Sin x','2 Sin x',0},[])


    if(exist('x')&&exist('y'))
    if(length(x)>=1&&length(x)==length(y))      
        DIMENSIONA=1;
        if(exist('rangs'))
            if(length(rangs)==5)
                DIMENSIONA=0;
            end
        end
        if(DIMENSIONA)
            rangs=[inf,inf,inf,inf,0.1];
        end
        
        if(rangs(1)==inf)
            t0=min(x{1});
            n=2;
            while(n<=length(x))
                if(min(x{n})>t0)
                    t0=min(x{n});
                end
                n=n+1;
            end
        else
            t0=rangs(1);
        end

        if(rangs(2)==inf)
            t1=max(x{1});
            n=2;
            while(n<=length(x))
                if(max(x{n})<t1)
                    t1=max(x{n});
                end
                n=n+1;
            end
        else
            t1=rangs(2);
        end

        if(rangs(3)==inf)
            m=1;
            while(x{1}(m)<t0)
                m=m+1;
            end
            M=length(x{1});
            while(x{1}(M)>t1)
                M=M-1;
            end
            y0=min(y{1}(m:M));
            n=2;
            while(n<=length(y))
                m=1;
                while(x{n}(m)<t0)
                    m=m+1;
                end
                M=length(x{n});
                while(x{1}(M)>t1)
                    M=M-1;
                end
                if(min(y{n}(m:M))<y0)
                    y0=min(y{n}(m:M));
                end
                n=n+1;
            end
        else
            y0=rangs(3);
        end

        if(rangs(4)==inf)
            m=1;
            while(x{1}(m)<t0)
                m=m+1;
            end
            M=length(x{1});
            while(x{1}(M)>t1)
                M=M-1;
            end
            y1=max(y{1}(m:M));
            n=2;
            while(n<=length(y))
                m=1;
                while(x{n}(m)<t0)
                    m=m+1;
                end
                M=length(x{n});
                while(x{1}(M)>t1)
                    M=M-1;
                end
                if(max(y{n}(m:M))>y1)
                    y1=max(y{n}(m:M));
                end
                n=n+1;
            end
        else
            y1=rangs(4);
        end

        rangy=y1-y0;
        
        ESTILITZA=0;
        ESTILITZA2=0;
        if(exist('stils'))
            if(length(stils)==length(x))
                ESTILITZA=1;
            end
        end
        if (~ESTILITZA)
            if(length(x)<6)
                suxorz={'r','g','b','c','m'};
                n=1;
                stils{1}=suxorz{1};
                while(n<=length(x))
                    stils{n}=suxorz{n};
                    n=n+1;
                end
            else
                ESTILITZA2=1;
                stils{1}=[0,0,0];
                n=2;
                while(n<=length(x))
                    stils{n}=[0.7,0.7,0.7]*(n-1)/(length(x)-1);
                    n=n+1;
                end
            end
        end

        if(exist('tipus'))
            if(isequal(tipus,'semilogx')==1)
                pintador=@semilogx;
            else
                if(isequal(tipus,'semilogy')==1)
                    pintador=@semilogy;
                else
                    if(isequal(tipus,'loglog')==1)
                        pintador=@loglog;
                    else
                        pintador=@plot;
                    end
                end
            end
        else
            pintador=@plot;
        end
        
        if (ESTILITZA2) handmela(1)=pintador(x{1},y{1},'Color',stils{1},'LineWidth',2);
        else handmela(1)=pintador(x{1},y{1},stils{1});
        end
        hold on;
        n=2;
        while(n<=length(x))
            if (ESTILITZA2) handmela(n)=pintador(x{n},y{n},'Color',stils{n},'LineWidth',2); 
            else handmela(n)=pintador(x{n},y{n},stils{n});
            end
            n=n+1;
        end
        grid on;
        if rangy==0 rangy=1e-3;
        end
        axis([t0,t1,y0-rangs(5)*rangy,y1+rangs(5)*rangy]);
        if(exist('llegenda'))
            if(length(llegenda)==length(x))
                n=1;
                while(isnumeric(llegenda{n}))
                    n=n+1;
                end
                cacona(1)=handmela(n);
                llista{1}=llegenda{n};
                n=n+1;
                while(n<=length(llegenda))
                    if (~isnumeric(llegenda{n}))
                        llista{length(llista)+1}=llegenda{n};
                        cacona(length(cacona)+1)=handmela(n);
                    end
                    n=n+1;
                end
                legend(cacona,llista);
            end
        end
        if(exist('llabels'))
            if(length(llabels)==2)
                xlabel(llabels{1});
                ylabel(llabels{2});
            end
        end
    end
    end
end
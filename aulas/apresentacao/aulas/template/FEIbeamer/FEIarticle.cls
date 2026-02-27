\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{FEIarticle}[2022/20/08 FEI article template]

\LoadClass[a4paper,12pt]{article}

\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage[top=1.5cm,bottom=1.5cm,left=1.5cm,right=1.5cm]{geometry}
\RequirePackage{kpfonts}
% \setlength{\parindent}{0in}
\setlength{\parskip}{1em}
\renewcommand{\baselinestretch}{1.0}
\RequirePackage[brazil]{babel}
\RequirePackage[nomessages]{fp}            % enable calc
\RequirePackage{graphicx}
\RequirePackage{microtype}
\RequirePackage{booktabs}
\RequirePackage[at]{easylist}
\usepackage[dvipsnames]{xcolor}
\RequirePackage{mathabx}                   % better math visual
\RequirePackage[utf8]{inputenc}            % handle latin characters
\RequirePackage[T1]{fontenc}
\RequirePackage{tikz}                      % drawing functions
\RequirePackage{indentfirst}
\RequirePackage{tabularx}
\RequirePackage{multirow}
\RequirePackage{textcomp}
\RequirePackage{etoolbox}
\RequirePackage{xkeyval}                   % functions options
\RequirePackage[most]{tcolorbox}
\RequirePackage[absolute]{textpos}

\RequirePackage{inconsolata} % listings font
\RequirePackage{listings}    % java configuration 
\lstset{language=Java,
  columns=fullflexible,
  numbers=left,
  numbersep=2pt,
  numberstyle=\scriptsize\color{gray!80!black},
  showspaces=false,
  showtabs=false,
  % breaklines=true,
  xleftmargin=0.4cm,
  showstringspaces=true,
  breakatwhitespace=true,
  keepspaces=true,
  % escapeinside={\%*}{*)},
  commentstyle=\color{pgreen},
  %keywordstyle=\color{pblue},
  keywordstyle=\color{FEImiddleblue}\bfseries,
  stringstyle=\color{pbrown},
  basicstyle=\normalsize\ttfamily\color{gray!30!black},
  extendedchars=true,
  inputencoding=utf8,
  literate=
  {ê}{{\^e}}1 
  {â}{{\^a}}1
  {á}{{\'a}}1
  {ú}{{\'u}}1
  {í}{{\'i}}1
  {ã}{{\~a}}1
  {é}{{\'e}}1
  {ç}{{\c{c}}}1
  {\{}{{\textbf{\textcolor{orange!70!black}{\{}}}}1
  {\}}{{\textbf{\textcolor{orange!70!black}{\}}}}}1
  {)}{{\textcolor{orange!70!black}{)}}}1
  {(}{{\textcolor{orange!70!black}{(}}}1,
  % {\{ }{\textcolor{red}{\{}}1,
  % {\}}{\textcolor{red}{\}}}1
  % {[}{\textcolor{green}{[}}1     
  % {]}{\textcolor{green}{]}}1    ,
  % }
  %moredelim=[il][\textcolor{pgrey}]{$$},
  %moredelim=[is][\textcolor{pgrey}]{\%\%}{\%\%}
}

%define colors
\definecolor{FEImiddleblue}{RGB}{0,110,171}
\definecolor{FEIdarkblue}{RGB}{48,92,142}
\definecolor{FEIlightblue}{RGB}{77,142,198}

% define listings colors
\definecolor{pblue}{rgb}{0.13,0.13,1}
\definecolor{pgreen}{rgb}{0,0.5,0}
\definecolor{pred}{rgb}{0.9,0,0}
\definecolor{pbrown}{rgb}{0.84,0.50,0.32}
\definecolor{pgrey}{rgb}{0.46,0.45,0.48}

\date{}


\newcommand{\pts}[1]{
  \ifdim#1 pt>1.0 pt
    \textbf{(#1 pts)}
  \else
    \textbf{(#1 pt)}
  \fi
}

\newcommand{\textgf}[1]{\textbf{\textcolor{FEIdarkblue}{#1}}}

\newcommand{\raw}{\rightarrow}

\newcommand{\bi}{\begin{easylist}\ListProperties(%   easylist itemize configuration
    Space1=0.08cm,
    Space=0.08cm,
    Space*=0.08cm,
    Space2=0.05cm,
    Space2*=0.05cm,
    Space3*=0.00cm,
    Space3=0.00cm,
    % Space2=0.8cm,
    Style1*=\textcolor{FEIdarkblue}{\textbullet}\hskip .5em,%
    Style2*=\textcolor{FEIdarkblue}{--}\hskip .5em,%
    Style2=\small,
    Style3*=\textcolor{FEIdarkblue}{$\boldsymbol{\cdot}$}\hskip .5em,%
    Style3=\footnotesize,
    Hang=true,
    Hide=1,
    Hide=2,
    Hide=3,
    Margin1=0.6cm,
    Margin2=1.0cm,
    Margin3=1.4cm,
  Margin4=1.6cm,)} 

\newcommand{\ei}{\end{easylist}}
\newcommand{\be}{\begin{easylist}\ListProperties(
    FinalSpace=0.5em, Hang=true, Mark=., 
    % Space=4pt, Space*=4pt,
    % Align=move,%
    Space1=0.1cm,
    Space=0.1cm,
    Space*=0.1cm,
    Space2=0.05cm,
    Space2*=0.05cm,
    Space3*=0.00cm,
    Space3=0.00cm,
    Start1=1,
    Style1*=\color{FEIdarkblue}\bfseries,
    Style2*=\hskip .5em\color{FEIdarkblue}{(},
    Style3*=\hskip .5em\color{FEIdarkblue},
    Mark2={)},
    Hide1=0,
    Hide2=1,
    Numbers2=l, 
    Numbers3=r,
    Hide3=2,
    Margin1=0.6cm,
    Margin2=1.0cm,
    Margin3=1.6cm,
  )}
\newcommand{\ee}{\end{easylist}}


% % create two columns with adjustable size. The informed parameter will be used
% % to define a percetage of the page used by th first column.
% % The remaining size will be filled by the second column
% \newcommand{\doublecolumn}[3][0.5]{% 
%   \begin{columns}[onlytextwidth,T]
%     \FPeval{\result}{clip(1.0-#1)}
%     \begin{column}{#1\textwidth}
%       #2
%     \end{column}
%     \begin{column}{\result\textwidth}
%       #3
%     \end{column}
%   \end{columns}
% }


% apply bold on both math an text objects
\newcommand\allbold[1]{{\boldmath\textbf{#1}}}

%---------------------------------
% define an exercise counter
\newcounter{exercisecounter}
\setcounter{exercisecounter}{0}% 
% call \exercise to write Exercise with a counter 
\newcommand{\exercise}{%
  \addtocounter{exercisecounter}{1}
  Exercício \theexercisecounter%
}
%----------------------------------



% ------------------ Nome and RA at the top of the page ----
\newcommand{\identification}{
  \begin{textblock}{1.0}(1.5,0.5)
    Nome:
  \end{textblock}
  \begin{textblock}{1.0}(11,0.5)
    RA:
  \end{textblock}
}
% --------------------------------------------------------------

% ------------------ show and hide solution ---------------------
\newif\ifshowsolution
\showsolutionfalse
\newcommand{\solution}[1]{\ifshowsolution\begingroup%
    \tt%
    \indent%
    \begin{tcolorbox}[breakable,colback=gray!5!white,colframe=gray!65!black,boxrule=0.2pt,after skip=0.1cm,before skip=0.1cm,,enhanced,title=Solução,fonttitle=\scriptsize,coltitle=gray!55!black,attach boxed title to top center={yshift=-3mm,yshifttext=-1mm},boxed title style={colframe=gray!65!black,boxrule=0.1pt,colback=gray!5!white}]
      \color{gray!55!black}#1
    \end{tcolorbox}%
    \vspace{0.8cm}
\endgroup\fi}%
\newcommand{\printsolution}{\showsolutiontrue}
% --------------------------------------------------------------


% ------------------ show and hide multiple choice solution ----
\newcommand{\correct}[1]{%
  \ifshowsolution%
    \textcolor{red}{#1}%
  \else%
    \ifshowanswer%
      \textcolor{red}{#1}%
    \else%
      #1%
    \fi%
  \fi%
}%

% --------------------------------------------------------------

% ------------------ show and hide answer ---------------------
\newif\ifshowanswer
\showanswerfalse
\newcommand{\answer}[1]{\ifshowanswer\begingroup%
    \tt%
    \indent%
    \begin{tcolorbox}[colback=blue!5!white,colframe=blue!65!black,boxrule=0.2pt,after skip=0.1cm,before skip=0.1cm,enhanced,title=Resposta,fonttitle=\scriptsize,coltitle=blue!55!black,attach boxed title to top center={yshift=-3mm,yshifttext=-1mm},boxed title style={colframe=blue!65!black,boxrule=0.1pt,colback=blue!5!white}]
      \color{blue!45!black}#1
    \end{tcolorbox}
\endgroup\fi}%
\newcommand{\printanswer}{\showanswertrue}
% --------------------------------------------------------------


% ------------------ show and hide version A ---------------------
\newif\ifshowversiona
\showversionafalse
\newcommand{\versionA}[1]{\ifshowversiona#1\fi}%
\newcommand{\printversionA}{\showversionatrue}
% --------------------------------------------------------------

% ------------------ show and hide version b ---------------------
\newif\ifshowversionb
\showversionbfalse
\newcommand{\versionB}[1]{\ifshowversionb#1\fi}%
\newcommand{\printversionB}{\showversionbtrue}
% --------------------------------------------------------------

% ------------------ exam header --------------------------------
\newcommand{\rastudent}{
  \begin{tikzpicture}
    \draw (-7.2,-1) node foreach \x in {1,...,8}[draw,minimum size=0.8cm] (\x) at (\x,0) {};
    \draw node[right of = 8](9){--};
    \draw node[draw,minimum size=0.8cm,right of = 9](10){};
    \draw node[left of = 1,xshift=0.2cm](N){N\textdegree};
    \draw node[draw,minimum width=1.6cm,minimum height=0.8cm,below of = 10,xshift=-0.4cm](square){};
    \draw node[left of = square,anchor=east]{N\textdegree\ \ SEQUENCIAL};
  \end{tikzpicture}
}
\newcommand{\fontchange}{\footnotesize}
\newcommand{\rulea}{\fontchange Leia e obedeça rigorosamente as instruções da prova.}
\newcommand{\ruleb}{\fontchange Preencha o cabeçalho da prova com os dados requeridos antes de assinar a folha de presença.}
\newcommand{\rulec}{\fontchange A prova é individual e sem consulta.}
\newcommand{\ruled}{\fontchange \textbf{A interpretação do texto faz parte da avaliação.}}
\newcommand{\rulee}{\fontchange Não é permitido o uso de folhas de rascunho avulsas para rascunho.}
\newcommand{\rulef}{\fontchange Não é permitido o empréstimo de materiais (lápis, borracha, grafite, etc) durante a prova.}
\newcommand{\ruleg}{\fontchange Os telefones celulares devem ser mantidos desligados.}
\newcommand{\ruleh}{\fontchange Tempo mínimo permanência: 30 min.}
\newcommand{\rulei}{\fontchange Tolerância entrada na sala: 15 min. após o início da prova.}
\newcommand{\rulej}{\fontchange Duração: 80 min.}
\newcommand{\rulek}{\fontchange \textbf{Indagações sobre as questões deverão ser realizados durante a vista de prova.}}
\newcommand{\rulel}{\fontchange \textbf{Consulta:} sim() nao(x)}
\newcommand{\rulem}{\fontchange \textbf{Calculadora simples:} sim() nao(x)}
\newcommand{\rulen}{\fontchange \textbf{Calculadora alpha numérica:} sim() nao(x)}
\newcommand{\ruleo}{\fontchange \textbf{Duração da prova:} 80 minutos}
\newcommand{\university}{\textbf{Centro Universitário da FEI}}
\newcommand{\professor}{Prof. Charles Ferreira}
\newcommand{\discipline}{\textbf{COD./ DISC.:} CC6270 - Sistemas Operacionais}
\newcommand{\feilogo}{\includegraphics[scale=0.3]{FEI_logo_2015.png}}
\newcommand{\makeheader}[4]{
  \resizebox{
    \textwidth}{!}{\begin{tabularx}{1.12\textwidth}{llX|lll}
        \toprule
        \feilogo\rastudent                                                   \\\midrule 
        \multicolumn{2}{l|}{\textbf{COD./ DISC.:} #2 - #1}                        & \textbf{#4}                           &  \multicolumn{1}{l}{\textbf{DATA:}} & \multicolumn{2}{l}{#3}        \\ \cmidrule{1-6}
        \multicolumn{3}{l|}{\textbf{NOME:}}                      &  \multirow{2}{*}{\textbf{NOTA:}}                                  &  &      \\ \cmidrule{1-3}
        \multicolumn{3}{l|}{\textbf{ASS.:}}                         &                                     &  &      \\ \midrule
        \multicolumn{3}{l}{\footnotesize\textbf{Instruções Gerais:}}   \\ % &   Quest. & Pontos &  Nota                       \\ \cline{4-6} 
        \multicolumn{3}{l}{\rulel}                          \\ %  &   1      &        &                             \\ \cline{4-6}
        \multicolumn{3}{l}{\rulen}                          \\ %  &   1      &        &                             \\ \cline{4-6}
        \multicolumn{3}{l}{\rulem}                          \\ %  &   1      &        &                             \\ \cline{4-6}
        \multicolumn{3}{l}{\ruleo}                          \\ %  &   1      &        &                             \\ \cline{4-6}
        \midrule
        \multicolumn{3}{l}{\rulea}                          \\ %  &   1      &        &                             \\ \cline{4-6}
        \multicolumn{3}{l}{\ruleb}                          \\ %  &   2      &        &                             \\ \cline{4-6} 
        % \multicolumn{3}{l}{\rulec}                          \\ %  &   3      &        &                             \\ \cline{4-6} 
        \multicolumn{3}{l}{\rulee}                          \\ %  &   5      &        &                             \\ \cline{4-6} 
        \multicolumn{3}{l}{\rulef}                          \\ %  &   6      &        &                             \\ \cline{4-6} 
        \midrule
        \multicolumn{3}{l}{\ruled}                          \\ %  &   4      &        &                             \\ \cline{4-6} 
        \multicolumn{3}{l}{\rulek}                          \\ %  &   7      &        &                             \\ \cline{4-6} 
        % \multicolumn{3}{l}{\ruleh}                          \\ %  &   8      &        &                             \\ \cline{4-6} 
        % \multicolumn{3}{l}{\rulei}                          \\ %  &   9      &        &                             \\ \cline{4-6}
        % \multicolumn{3}{l}{\rulej}                         \\
        \bottomrule  %  &   10     &        &                             \\ \bottomrule 
      \end{tabularx}
    }
  }

  % ------------------ grouptable definition --------------------------------

  % https://tex.stackexchange.com/questions/367979/latex-foreach-in-tabular-environment
  \newcommand{\GTgroups}{1}
  \define@key{generictable}{groups}{%
    \renewcommand{\GTgroups}{#1}
  }
  \newcommand{\GTspace}{0.0}
  \define@key{generictable}{space}{%
    \renewcommand{\GTspace}{#1}
  }
  \def\addtablerow#1!{\textbf{#1} & \\ \midrule}
  \newcommand{\genericTable}[1]{
    \renewcommand*\do[1]{\addtablerow##1!}
    \begin{tabularx}{\textwidth}{X|l}
      \multicolumn{2}{l}{\textbf{Componentes do grupo (\hspace{0.5cm})}} \vspace{0.2cm}\\ 
      \toprule
      \textbf{Nome} & \textbf{RA} \textcolor{white}{(registro acadêmico)} \\ \midrule
      \docsvlist{#1}  
    \end{tabularx}
  }
  \newcommand{\grouptable}[2][]{
    \setkeys{generictable}{groups=1,space=0.0,#1}
    \foreach \n in {1,...,\GTgroups}{
      \vspace{\GTspace cm}

      \noindent
      \genericTable{#2}
    }
  }


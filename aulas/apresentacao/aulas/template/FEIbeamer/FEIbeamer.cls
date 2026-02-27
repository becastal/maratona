\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{FEIbeamer}[2021/07/26 beamer template]

\RequirePackage{kvoptions}
% Declare a string option `fntsize' that is unique to the derived
% class `FEIbeamer'. It will accept anything assuming `14pt' if
% unspecified.
\DeclareStringOption[14pt]{fntsize}
% probably more options...
\DeclareStringOption[aspectratio=169]{aspectratiosize}

\ProcessKeyvalOptions{FEIbeamer}\relax
\PassOptionsToClass{\FEIbeamer@fntsize}{beamer}
\PassOptionsToClass{\FEIbeamer@aspectratiosize}{beamer}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{beamer}} % allow to pass options 
% to another class
\ProcessOptions\relax%

\LoadClass{beamer}

\RequirePackage{beamerfunctions}
\RequirePackage{microtype}
\RequirePackage{xcolor}                    % add colors
\RequirePackage[utf8]{inputenc}            % handle latin characters

\RequirePackage{xkeyval}                   % functions options
\RequirePackage[T1]{fontenc}
\RequirePackage{graphicx}                  % pictures managnment
\RequirePackage{libertine}                 % font libertine
\RequirePackage{pbsi}                      % BrushScriptX-Italic font
% \RequirePackage{rotunda}
% \RequirePackage{montserrat}                 % font montserrat
% \RequirePackage{roboto}                   % font roboto
% \RequirePackage{raleway}                  % font raleway
\RequirePackage[brazil]{babel}             % pt br language support
\usepackage{silence}                       % silence warnings
\WarningFilter{microtype}{Unable to apply patch}
\RequirePackage{ifthen}
\RequirePackage{listings}    % java configuration 
\RequirePackage{listingsutf8}
\RequirePackage[at]{easylist}              % better list manipulation
\RequirePackage{inconsolata} % listings font

% slides visual for general presentation
\mode<beamer>{%
  \useoutertheme{FEI}
  \useinnertheme{FEI}
  \usecolortheme{FEI}
  \usefonttheme{FEI}
}

% slides visual for handout presentation
\mode<handout>{%           % no animations
  \useoutertheme{FEI}
  \useinnertheme{FEI}
  \usecolortheme{FEI}
  \usefonttheme{FEI}
}


% \definecolor{light}{rgb}{0.04706, 0.13725, 0.26667} % 
% \definecolor{middle}{rgb}{0.04706, 0.13725, 0.26667} % 
% \definecolor{middle}{RGB}{0,110,171} % 

% change an already defined color
\colorlet{middle}{FEImiddleblue}
\colorlet{light}{FEIlightblue}
\colorlet{dark}{FEIdarkblue}

\lstset{%
  language=Java,
  frame=leftline,
  columns=fullflexible,
  numbers=left,
  numbersep=6pt,
  numberstyle=\scriptsize\ttfamily\color{gray!80!black},
  showspaces=false,
  showtabs=false,
  % breaklines=true,
  xleftmargin=1cm,
  showstringspaces=false,
  breakatwhitespace=true,
  commentstyle=\color{green!50!black},
  keywordstyle=\color{middle}\bfseries,
  stringstyle=\color{orange!70!black},
  basicstyle=\footnotesize\ttfamily\color{gray!70!black},
  extendedchars=true,
  inputencoding=utf8/latin1,
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
  % {)}{{\textcolor{orange!70!black}{)}}}1
  % {(}{{\textcolor{orange!70!black}{(}}}1
  {]}{{\textcolor{orange!70!black}{]}}}1
  {[}{{\textcolor{orange!70!black}{[}}}1,
}


\newcommand{\bi}{%
  \begin{easylist}\ListProperties(%   easylist itemize configuration
    Space1=-0.2cm,
    Space=-0.2cm,
    Space2=-0.3cm,
    Space*=-0.2cm,
    Space2*=-0.3cm,
    Space3*=-0.40cm,
    Space3=-0.40cm,
    Style1*=\textcolor{middle}{\textbullet}\hskip .5em,%
    Style2*=\textcolor{middle}{--}\hskip .5em,%
    Style3*=\textcolor{middle}{$\boldsymbol{\cdot}$}\hskip .5em,%
    Hang=true,
    Hide=1000,
    Margin1=0.2cm,
    Margin2=0.6cm,
    Margin3=1.0cm,
    Margin4=1.2cm,)
  } 
\newcommand{\ei}{\end{easylist}}

\newcommand{\be}{%
  \begin{easylist}\ListProperties(
    FinalSpace=0.5em, Hang=true, Mark=., 
    Start1=1,
    Style1*=\color{middle}\bfseries,
    Style2*=\hskip .5em\color{middle}{(},
    Style3*=\hskip .5em\color{middle},
    Mark2={)},
    Hide1=0,
    Hide2=1,
    Numbers2=l, 
    Numbers3=r,
    Hide3=2,
    Margin1=0.0cm,
    Margin2=0.4cm,
    Margin3=1.2cm,
    )
  }
\newcommand{\ee}{\end{easylist}}

% left and righ margin
\setbeamersize{text margin left=0.4cm,text margin right=0.4cm} 
\setlength{\parskip}{\baselineskip}


\newcommand{\FBtextwidth}{-1}
\define@key{feibox}{textwidth}{%
  \renewcommand{\FBtextwidth}{#1}
}
\newcommand{\FBalign}{center}
\define@key{feibox}{align}{%
  \renewcommand{\FBalign}{#1}
}
\newcommand{\FBfont}{\normalsize}
\define@key{feibox}{font}{%
  \renewcommand{\FBfont}{#1}
}
\newcommand{\feibox}[2][]{
  \setkeys{feibox}{align=center,#1}
  {\centering
    \tikzstyle{roundedbox}=[line width=1pt,draw=FEImiddleblue,fill=FEIlightblue!10!white,minimum width=2cm,minimum height=2cm,rounded corners]
    \ifthenelse{\equal{\FBtextwidth}{-1}}{%
        \tikz\node[roundedbox,align=\FBalign,font=\FBfont]{#2};
      }{%
        \tikz\node[roundedbox,align=\FBalign,font=\FBfont,text width=\FBtextwidth cm]{#2}; 
      } % there is an intentional \n to proper work 

    }
  }

  % title page information (should be override)
  \author[e-mail]{Professor}
  \title{Class name}
  \subtitle{Course name}


  % disable titlepagle and endpage
  \newboolean{hascover}
  \setboolean{hascover}{true}
  \newcommand{\nocover}{\setboolean{hascover}{false}}




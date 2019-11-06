# LaTeX notes

## Basics

`\documentclass` is used to specify type of the document. Available types:

* `article`
* `proc`
* `minimal`
* `report`
* `book`
* `slides`
* `memoir`
* `letter`
* `beamer`

`\maketitle` creates title with information specified by commands like `\title{}`, `\author{}`, `\date{}`.

`\section{}` is used to structure document logically. You can create `\subsection{}`, `\subsubsection{}` and so on.

You can comment out LaTeX command with `%` sign.

## Math

To insert inline math include it in dollar signs:

```TeX
You can write maths like this: $ 2 + 3 = 5 $
```

Some basic examples:

```TeX
Superscript: $ x^{3} $
Subscript: $ x_{2} $
Alpha, Lambda and other friends: $ \alpha, \lambda, \beta, \gamma $
Capitalized: $ \A, \Lambda, \B, \Gamma $
Sin: $ \sin{z} $
Square root: $ \sqrt{9} $
Fraction: $ \frac{3}{4} $
Subset: $ y \subseteq Z $
Log: $ \log{n} $
```

Big statements use `\begin{equation}` and `\end{equation}` syntax:

```TeX
\begin{equation}
x^5 - 7x^3 + 4x
\end{equation}

\begin{equation}
\sum_{n=1}^{10} \log{n} % sum
\end{equation}

\begin{equation*}
\int_{2}^{3} x^2 dx % integral
\end{equation}
```

## Images

To use images in the document you'd have to enable `graphicx` package:

```TeX
\usepackage{graphicx}

\includegraphics[scale=2, angle=45]{filename}
```

To insert image you need to use `\includegraphics` with filename without extension. This statement supports parameters. Possible options:

* scale
* height
* width
* angle

If you need to create caption for the image, `figure` environment is way to go. By default it creates figure on separate page, but you can specify `h` option which stands for *here*, `b` for bottom and `t` for top of the page. Another option is `p` – put it on separate page. You can add `!` (exclamation mark) to override LaTeX idea of where should we put the image. Lastly, there is *capital H* (`H`) which places image at exact location. To use this is you may need to use `float` package.

```TeX
\begin{figure}[h]
\centering
\includegraphics[width=64, height=64]={beatifulCat}
\caption{This is the picture of beatiful cat}
\label{fig:cat}

% somewhere else in the document
See figure \ref{fig:cat} on page \pageref{fig:cat}
\end{figure}
```

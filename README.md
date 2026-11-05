*This project has been created as part of the 42 curriculum by kosaito.*

## Description


ft_printfはC言語標準printfを自作し、挙動を比較する課題です。

## Instructions

ft_printfの提出物にはMakefileが含まれているため、makeコマンドでlibftprintf.aをビルドします。

make cleanで、オブジェクトファイル(.o)をすべて削除することが可能です。

fcleanで、make cleanを実行したあとにlibftprintf.a も削除することが可能です。

reルールで、make fcleanを実行したあとにmake allを実行することができます。

## Algorithm

ft_printfの制作にあたり、私は前回の課題で作成したlibftを利用しませんでした。
理由は、libftで作成したft_putchar_fdやft_putstr_fdは戻り値がvoidであるため、libftを流用すると、文字列を数える仕組みを別で作らなければいけなかったからです。

ft_print_utils 内で自作したft_putchar 、ft_putstr、ft_putnbr、ft_puthexは 、すべて出力した文字数をintで返せるようになっています 。

### ft_printf.c

**ft_printf**で文字列を読み込みます。
引数として` const char *format, ... `を受け取ります。

例えば、`ft_printf("[%d][%i][%d]\n",0,42,-42)`としたとき、

formatには `"[%d][%i][%d]\n"`
...の1つ目に **0(args0)**

2つ目に **42(args1)**

3つ目に **-42(args2)**

が入ります。

### va_listとは

マクロとは、ソースコードをコンパイルする前の前処理プリプロセスの段階で、特定の文字列を指定した文字列や式に置換する機能のことです。

**va_arg**は、**<stdarg.h>** で用意されているマクロです。
C言語で可変長引数（渡す引数の数が固定されていない関数）のリストから、次の引数を取り出すために使うマクロです。

**va_list** は、**<stdarg.h>** で用意されている型です。
この変数には、...で受け取った引数のうち、次に読む場所の読み取り位置が入ります。
今回は**args**という名前で定義しています。

**va_start**は、**<stdarg.h>** で用意されているマクロで、可変長引数を読み始める前に必ず1回呼ばなければいけないものです。

**va_end** は、**<stdarg.h>** で用意されているマクロで、可変長引数を読み終わったときに必ず1回呼ばなければいけないものです。
**va_start**を使用したときは、**va_end**を使用します。


### whileループで何をしているか

変数**i**はループを進めるためのカウンターです。
**count**は文字数のカウンターです。
countを最後に返すことで、printfが何文字なのかわかるようになっています 。


ft_printf内のループでは、与えられた文字列内に'%'が含まれているかどうか、文字列を先頭から見て調べています。
format[i]に%が見つかった場合、countにft_formatを足し込みます。

format[i]に'%'が見つからなかった場合、countにft_putcharを足し込みます。

format[i]が、`"ab%"`のように%で終わる文字だった場合も、countにft_putcharを足し込みます。


### ft_format関数

ft_format関数では、%の後の文字を読んで条件分岐を行っています。

**%cのとき**

%cは文字型です。
%cのとき、ft_putcharを使います。
戻り値はintです。

**%dまたは%iのとき**

%dまたは%iのとき、ft_putnbrを使います。
戻り値はintです。
%d、%iは10進数用の型です。

**%sのとき**

%sは文字列型です。
ft_putstrを使います。
戻り値はintです。

**%uのとき**

%uはunsigned int型です。
ft_putnbrを使います。
戻り値はint型です。

**%xのとき**

%xは小文字の16進数です。
ft_puthexを使います。
ft_puthex(va_arg(*args, unsigned int),"0123456789abcdef", err))と書くと長いので
HEX_LOWを使っています。
HEX_LOWは.hファイル内で `# define HEX_LOW "0123456789abcdef"`と定義しています。

**%Xのとき**

%Xは大文字の16進数です。
%xと同じようにft_puthexを使います。
%xと同様、長いのでHEX_UPを定義しています。

**%pのとき**

%pはポインタ(メモリアドレス)を16進数で表示するための変換指定子です。
ft_putptrを使います。

### ft_print_utils.c

ft_print_utils.cに、ft_printfで使用する関数5つをまとめています。
int *errでエラー処理を行っています。

**ft_putchar**

1文字出力する

**ft_putnbr**

数字を出力する

**ft_putstr**

文字列を出力する

**ft_puthex**

16進数に変換して出力する

**ft_putptr**

メモリアドレスを出力する。


## Resources

### Use of AI

生成AI(Claude)を、次の作業に使用しました。

・課題文章の翻訳
・概念の解説（可変長引数、値渡しとポインタ渡し、Makefile、16進数など）
・エラーメッセージの翻訳
・コンパイルエラー原因の特定
・採用アルゴリズムの相談
・Normの行数を減らす方法の相談
・write失敗時のテスト

### Tester

https://github.com/Tripouille/printfTester

printfTesterを使用しました。

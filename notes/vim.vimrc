set nu
syntax on
set hls
set laststatus=2
set tags=tags;/
set cursorline
set mouse=
set tabstop=4
set expandtab
%retab! 4
set shiftwidth=4
set ci

if has("multi_byte")

" UTF-8

    set encoding=utf-8

    set termencoding=utf-8

    set formatoptions+=mM

    set fencs=utf-8,gbk

if v:lang =~? '^\(zh\)\|\(ja\)\|\(ko\)'

    set ambiwidth=double

endif

if has("win32")

    source $VIMRUNTIME/delmenu.vim

    source $VIMRUNTIME/menu.vim

    language messages zh_CN.utf-8

endif

else

    echoerr "Sorry, this version of (g)vim was not compiled with +multi_byte"

endif

au BufNewFile,BufRead *.cl set filetype=c

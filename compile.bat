@echo off

set name="dice-nuts"

set path=%path%;..\bin\

set CC65_HOME=..\

cc65 -Oirs %name%.c --add-source
ca65 crt0.s
ca65 build/%name%.s -g

ld65 -C nrom_32k_vert.cfg -o %name%.nes crt0.o build/%name%.o nes.lib -Ln labels.txt --dbgfile dbg.txt

del *.o

move /Y labels.txt build\ 
move /Y %name%.s build\ 
move /Y %name%.nes build\ 

@REM pause

@REM build\%name%.nes

@echo off

set name="dice-nuts"

set path=%path%;..\bin\

set CC65_HOME=..\

:: Compile all C files to assembly
cc65 -Oirs %name%.c --add-source -o build/%name%.s
cc65 -Oirs src/gameplay.c --add-source -o build/gameplay.s
cc65 -Oirs src/graphics.c --add-source -o build/graphics.s
cc65 -Oirs src/player_actions.c --add-source -o build/player_actions.s

:: Assemble all .s files to object files
ca65 crt0.s
ca65 build/%name%.s -g
ca65 build/gameplay.s -g
ca65 build/graphics.s -g
ca65 build/player_actions.s -g

ld65 -C nrom_32k_vert.cfg -o %name%.nes crt0.o build/%name%.o build/gameplay.o build/graphics.o build/player_actions.o nes.lib -Ln labels.txt --dbgfile dbg.txt

del *.o

move /Y labels.txt build\ 
move /Y %name%.s build\ 
move /Y src/graphics.s build\
move /Y %name%.nes build\ 

@REM pause

@REM build\%name%.nes

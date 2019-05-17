@echo off
rem	-------------------------------------------------------------------------
rem	Write by ZAP 2006-06-24
rem	-------------------------------------------------------------------------
rem	_MODNAME_:	Current Module Name
rem	_MODTYPE_:	Current Module Type
rem	_RUNPATH_:	Current Run result path
rem	_COMPILE_:	Current Module Compile mode
rem	-------------------------------------------------------------------------

	set _MODNAME_=GxxCryptoTool
	set _MODTYPE_=exe
	set _RUNPATH_=..\bin\release
	set _COMPILE_=Release

	if "%_COMPILE_CMD_%"=="32D"	set _COMPILE_=Debug
	if "%_COMPILE_CMD_%"=="32R"	set _COMPILE_=Release
	if "%_COMPILE_CMD_%"=="32D"	set _RUNPATH_=..\bin\debug
	if "%_COMPILE_CMD_%"=="32R"	set _RUNPATH_=..\bin\release


rem	-----------------------------ToDo Other Begin!--------------------------
rem	-----------------------------ToDo Other End!----------------------------

echo	-------------------------------------------------------------------------
echo	BUILD:	%_RUNPATH_%\%_MODNAME_%.%_MODTYPE_%
echo	-------------------------------------------------------------------------
		
	del %_RUNPATH_%\%_MODNAME_%.%_MODTYPE_%
	del %_RUNPATH_%\*.exp
	del %_RUNPATH_%\*.pdb
	del %_RUNPATH_%\*.lib
	del %_RUNPATH_%\*.ilk
	del temp /q

rem	更新RC文件
	copy /a	"xResource.rc"+"..\ZShareFiles\ZVersion.rc" "ZResource.rc"
	
	call 	"%QT4.8.1_ROOT%\msvc2008\bin\qtenv2.bat"
	call 	"%MVS2008_ROOT%\VC\bin\vcvars32.bat"
	qmake	%_MODNAME_%.pro
	nmake	clean
	nmake	-f Makefile.%_COMPILE_%
	IF ERRORLEVEL==1 goto ERROR

	del %_RUNPATH_%\*.exp
	del %_RUNPATH_%\*.pdb
	del %_RUNPATH_%\*.lib
	del %_RUNPATH_%\*.ilk
	del temp\*	/a
	del *.suo	/a
	del *.ncb	/a
	del *.aps	/a
	del *.idc	/a
	del *.idb	/a
	del *.pdb	/a
	del Makefile	/a
	del Makefile.Debug	/a
	del Makefile.Release	/a
	del ui_*.h	/a
	rd /s/q temp
	rd /s/q debug
	rd /s/q release
	rd /s/q GeneratedFiles
	rd /s/q Win32


	goto EXIT
rem	-------------------------------------------------------------------------



:ERROR
echo	-------------------------------------------------------------------------
echo	Build Error!  %_MODNAME_%.%_MODTYPE_%
echo	-------------------------------------------------------------------------
	pause
	exit -1


:EXIT
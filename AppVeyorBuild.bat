echo on

start AppVeyorScreenshots.bat

SET NPACKD_CL=C:\Program Files (x86)\NpackdCL
set path=%SystemRoot%;%SystemRoot%\system32;C:\Program Files\AppVeyor\BuildAgent\
@cscript TestUnstableRep.js /password:%password%


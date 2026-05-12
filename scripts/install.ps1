param(
    [string]$OutputPath = "cputils.h"
)

$ErrorActionPreference = "Stop"
$uri = "https://github.com/himaenshuu/cputils/releases/latest/download/cputils.h"

Invoke-WebRequest -UseBasicParsing -Uri $uri -OutFile $OutputPath
Write-Output "Installed cputils.h to $OutputPath"

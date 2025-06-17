// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// 현재 네트워크 모드를 문자열로 반환
#define LOG_NETMODEINFO                                         \
    ((GetNetMode() == ENetMode::NM_Client)                      \
        ? *FString::Printf(TEXT("Client%d"), GPlayInEditorID)   \
        : (GetNetMode() == ENetMode::NM_Standalone)             \
            ? TEXT("StandAlone")                                \
            : TEXT("Server"))


// 이 로그가 어떤 함수 내부에서 찍혔는지 텍스트로 반환
#define LOG_CALLINFO                                            \
    ANSI_TO_TCHAR(__FUNCTION__)


// [Server/StandAlone/Client] FuncName LogText
#define AB_LOG(LogCategory, Verbosity, Format, ...)             \
    UE_LOG(LogCategory,                                         \
           Verbosity,                                           \
           TEXT("[%s] %s %s"),                                  \
           LOG_NETMODEINFO,                                     \
           LOG_CALLINFO,                                        \
           *FString::Printf(Format, ##__VA_ARGS__))


// 구분용 로그 카테고리 선언
DECLARE_LOG_CATEGORY_EXTERN(LogABNetwork, Log, All);
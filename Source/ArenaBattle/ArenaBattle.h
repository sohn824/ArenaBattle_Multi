// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// ���� ��Ʈ��ũ ��带 ���ڿ��� ��ȯ
#define LOG_NETMODEINFO                                         \
    ((GetNetMode() == ENetMode::NM_Client)                      \
        ? *FString::Printf(TEXT("Client%d"), GPlayInEditorID)   \
        : (GetNetMode() == ENetMode::NM_Standalone)             \
            ? TEXT("StandAlone")                                \
            : TEXT("Server"))


// �� �αװ� � �Լ� ���ο��� �������� �ؽ�Ʈ�� ��ȯ
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


// ���п� �α� ī�װ� ����
DECLARE_LOG_CATEGORY_EXTERN(LogABNetwork, Log, All);
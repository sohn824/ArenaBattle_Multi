// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/ABGameState.h"
#include "ArenaBattle.h"

/** �� �ݹ� ���� ������ ���۵� ������ ��޵Ǹ� ������ GameMode�� BeginPlay�� ȣ���� */
void AABGameState::HandleBeginPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::HandleBeginPlay();

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

/** ������ GameMode���� ������ ���۵����� �˷��ָ� Ŭ���̾�Ʈ���� �� ����(Replicate) �ݹ��� ȣ��� */
void AABGameState::OnRep_ReplicatedHasBegunPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::OnRep_ReplicatedHasBegunPlay();

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/ABGameState.h"
#include "ArenaBattle.h"

/** 이 콜백 이후 게임이 시작된 것으로 취급되며 서버의 GameMode가 BeginPlay를 호출함 */
void AABGameState::HandleBeginPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::HandleBeginPlay();

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

/** 서버의 GameMode에서 게임이 시작됐음을 알려주면 클라이언트들은 이 복제(Replicate) 콜백이 호출됨 */
void AABGameState::OnRep_ReplicatedHasBegunPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::OnRep_ReplicatedHasBegunPlay();

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

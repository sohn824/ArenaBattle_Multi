// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "ABGameMode.h"
#include "Player/ABPlayerController.h"
#include "ArenaBattle.h"
#include "ABGameState.h"

AABGameMode::AABGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/Engine.Blueprint'/Game/ArenaBattle/Blueprint/BP_ABCharacterPlayer.BP_ABCharacterPlayer_C'"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/ArenaBattle.ABPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}

	// 사용할 GameState 지정
	GameStateClass = AABGameState::StaticClass();
}

void AABGameMode::OnPlayerDead()
{

}

/**
 * 서버에 접속하려는 플레이어를 수락하거나 거부함
 * ErrorMessage를 빈 문자열이 아닌 값으로 설정하면 해당 플레이어는 로그인에 실패함
 * PreLogin은 Login보다 먼저 호출됨
 * 이후 Login이 호출되기까지 상당한 게임 시간이 흐를 수 있음
 *
 * @param	Options					플레이어가 전달한 URL 옵션들 (예: 이름/관전자 모드 등)
 * @param	Address					플레이어의 네트워크 주소
 * @param	UniqueId				플레이어가 서버에 전달한 고유 ID
 * @param	ErrorMessage			빈 문자열이 아닌 값으로 설정되면, 해당 오류 메시지를 사용해 플레이어의 접속을 거부
 */
void AABGameMode::PreLogin(const FString& Options,
	const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

/**
 * 새로운 플레이어의 로그인을 처리하기 위해 호출되며, 게임에서 override할 수 있음
 *
 * 플레이어의 기본 속성(이름, 고유 ID, 백엔드 등록 등)을 설정하며, 복잡한 게임 로직을 수행해서는 안 됨
 * 이 함수 내에서는 네트워크 관점에서 PlayerController가 완전히 초기화되지 않은 상태임
 * 실제 게임 로직은 이후에 호출되는 PostLogin에서 처리해야 함
 *
 * @param NewPlayer 이 플레이어를 나타내는 UPlayer 객체에 대한 포인터 (로컬 또는 원격)
 * @param RemoteRole 이 컨트롤러가 가지는 원격 역할
 * @param Portal 클라이언트가 지정한 포탈 위치
 * @param Options 클라이언트가 로그인 시 전달한 게임 옵션들
 * @param UniqueId 로그인하는 플레이어의 플랫폼 고유 식별자
 * @param ErrorMessage [출력] 로그인 실패 시 사유가 되는 오류 메시지
 *
 * 로그인이 성공하면, 이 플레이어와 연결할 새로운 PlayerController를 반환함
 * ErrorMessage 문자열이 설정되면 로그인이 실패함
 *
 * @return 로그인한 플레이어를 위한 새로운 PlayerController, 실패한 경우 NULL 반환
 */
APlayerController* AABGameMode::Login(UPlayer* NewPlayer,
	ENetRole InRemoteRole, const FString& Portal, const FString& Options,
	const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	APlayerController* NewPlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));

	return NewPlayerController;
}

/**
 * 로그인에 성공한 후 호출됨
 * 이 시점부터 PlayerController에서 복제(replicated) 함수를 안전하게 호출할 수 있음
 */
void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::PostLogin(NewPlayer);

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}

/**
 * 이 콜백이 호출된 후 액터들에 대해 BeginPlay를 호출하는 단계로 전환됨
 */
void AABGameMode::StartPlay()
{
	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("Start"));

	Super::StartPlay();

	AB_LOG(LogABNetwork, Log, TEXT("%s"), TEXT("End"));
}


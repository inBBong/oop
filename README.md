# OOP 단계별 프로젝트: Banking System

『윤성우의 열혈 C++ 프로그래밍』의 "OOP 단계별 프로젝트"를 따라 구현한 콘솔 은행 계좌 관리 프로그램입니다.
절차지향 코드에서 시작해 클래스, 상속, 연산자 오버로딩, 템플릿, 예외 처리를 한 단계씩 적용하며 같은 프로그램을 리팩터링했습니다.

## 기능

- 계좌 개설 (보통예금계좌 / 신용신뢰계좌)
- 입금 (계좌 종류와 신용등급에 따른 이자 적용)
- 출금 (잔액 부족 시 예외 처리)
- 전체 계좌 정보 조회

## 단계별 변경 내역

| 단계 | 위치 | 적용한 내용 |
|---|---|---|
| 0.1 | `oop.0.cpp` | 전역 함수와 구조체 기반의 기본 틀 |
| 0.2 | `oop.1.cpp` | `Account` 클래스 도입, 이름을 동적 할당으로 관리 |
| 0.3 | `oop.2.cpp` | 깊은 복사 생성자 정의 |
| 0.3 | `oop.3.cpp` | 상태를 바꾸지 않는 멤버 함수를 `const`로 선언 |
| 0.4 | `oop.4.cpp` | 컨트롤 클래스 `AccountHandler` 도입 |
| 0.5 | `oop.5.cpp` | 상속: `NormalAccount`, `HighCreditAccount` 추가 |
| 0.6 | 루트의 `Account`, `AccountHandler`, `BankingSystemMain.cpp` 등 | 헤더/소스 파일 분할 |
| 0.7 | `oop.11/` (루트의 `*07` 파일과 동일) | 경계 검사 배열 클래스 `BoundCheckAccountPtrArray`, 대입 연산자 정의 |
| 0.8 | `oop.8/` | `char*` 대신 직접 만든 `String` 클래스 사용 |
| 0.9 | `oop.9/` | 배열 클래스를 템플릿(`BoundCheckArray`)으로 일반화 |
| 0.10 | `oop.10/` | 입금·출금 예외 클래스(`DepositException`, `WithdrawException`)와 `try`/`catch` 적용 |

가장 최신 버전은 `oop.10/` 입니다.

## 그 밖의 파일

`HelloWorld.cpp`, `FunctionOverloading.cpp`, `DefaultValue*.cpp`, `InlineFunc.cpp`, `NameSp*.cpp`, `UsingDcl*.cpp` 등은
책 1~2장의 C++ 기초 문법(함수 오버로딩, 디폴트 인자, 인라인 함수, 네임스페이스) 예제입니다.

## 빌드 및 실행

- 환경: Windows, Visual Studio 2022 (MSVC v143)
- `윤성우의 열혈 C++.sln`을 열고 실행할 단계의 소스만 빌드에 포함한 뒤 실행합니다.
  여러 단계에 `main` 함수가 있으므로 나머지 파일은 프로젝트에서 "빌드에서 제외"로 설정해야 합니다.
- 소스 파일은 CP949(EUC-KR)로 저장되어 있습니다.

1. pages 테이블
웹페이지 자체에 대한 기본적인 정보를 저장합니다.

필드명	데이터 타입	설명
page_id	INT	페이지의 고유 ID (Primary Key)
url	VARCHAR	페이지의 전체 URL
title	VARCHAR	페이지의 HTML 제목 (<title> 태그)
description	TEXT	페이지의 요약 정보 (<meta name="description">)
content_text	LONGTEXT	페이지 본문의 텍스트 내용
last_crawled_at	DATETIME	마지막으로 크롤링된 시간
ranking_score	FLOAT	페이지의 중요도 및 순위 점수

Sheets로 내보내기
2. keywords 테이블
각 키워드와 고유 ID를 매핑하는 테이블입니다.

필드명	데이터 타입	설명
keyword_id	INT	키워드의 고유 ID (Primary Key)
keyword	VARCHAR	검색 키워드 (예: "C++ 프로그래밍")

Sheets로 내보내기
3. inverted_index 테이블
가장 중요한 역색인(Inverted Index) 테이블입니다. 어떤 키워드가 어느 페이지에 있는지 효율적으로 찾을 수 있도록 돕습니다.

필드명	데이터 타입	설명
keyword_id	INT	keywords 테이블의 키워드 ID (Foreign Key)
page_id	INT	pages 테이블의 페이지 ID (Foreign Key)
position	INT	키워드가 페이지에서 나타난 위치
frequency	INT	페이지에 키워드가 나타난 횟수

Sheets로 내보내기
4. links 테이블
웹페이지 간의 연결 관계(하이퍼링크)를 저장합니다. 페이지의 권위를 계산하는 데 사용됩니다.

필드명	데이터 타입	설명
source_page_id	INT	링크가 시작된 페이지의 ID
target_page_id	INT	링크가 연결된 페이지의 ID
anchor_text	VARCHAR	링크에 사용된 텍스트 (예: "더 알아보기")

Sheets로 내보내기
5. users 테이블 (선택 사항)
사용자 개인화 서비스를 제공할 경우, 사용자의 검색 기록이나 선호도를 저장합니다.

필드명	데이터 타입	설명
user_id	INT	사용자의 고유 ID (Primary Key)
search_query	VARCHAR	사용자가 입력한 검색어
timestamp	DATETIME	검색이 이루어진 시간

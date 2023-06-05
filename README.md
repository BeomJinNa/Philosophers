# Philosophers

## 개요

스레드 (Thread): 스레드는 프로세스 내에서 실행되는 하나의 작업 흐름으로. 스레드는 다른 스레드와 메모리 공간을 공유하면서 독립적으로 실행되므로, 데이터를 공유하면서 병렬처리를 할 수 있다.

pthread_create & pthread_join: POSIX 스레드를 생성하는 함수는 pthread_create이며, 스레드의 작업이 끝날 때까지 기다리는 함수는 pthread_join이다. 스레드가 종료되면 그 반환 값을 얻을 수 있다.

pthread_detach: pthread_detach 함수는 생성된 스레드의 종료와 관련된 리소스를 자동으로 정리하게 만든다. 따라서 pthread_join을 호출하지 않아도 리소스 누수가 발생하지 않는다.

뮤텍스 (Mutex): 뮤텍스는 공유 데이터에 대한 동시 액세스를 제어하기 위해 사용되는 동기화 기술이다. 뮤텍스는 일반적으로 한 스레드가 한 번에 하나의 작업만 수행할 수 있도록 하는 락 메커니즘을 제공한다.

세마포어 (Semaphore): 세마포어는 뮤텍스와 유사하지만, 뮤텍스와는 달리 한 번에 여러 스레드가 동시에 리소스에 접근할 수 있게 한다. 리소스의 사용 가능 수량이 한정적인 경우에 주로 사용된다.

오류 처리: pthread 함수들은 실패 시 0이 아닌 값을 반환한다. 이 오류값은 errno.h에 정의된 매크로를 통해 확인할 수 있다. 함수 호출 후 반환값을 확인하여 오류를 처리하는 것이 좋다.

스레드를 사용하면서 가장 중요한 것은 동시성 문제를 관리하는 것으로, 뮤텍스와 세마포어를 적절히 활용하면 여러 스레드가 동시에 작업을 수행하더라도 데이터 무결성을 유지할 수 있다. 또한, 쓰레드의 생성과 종료에 관한 관리도 중요한데, 이는 운영체제나 라이브러리가 대부분 처리해준다.그러나 필요에 따라 명시적으로 리소스를 해제해주는 것도 중요하다.

## 헤더 파일

`<pthread.h>`:
POSIX 스레드를 사용하기 위한 함수, 타입, 상수 등이 정의되어 있는 헤더 파일

`<stdio.h>`:
표준 입출력 관련 함수가 정의되어 있는 헤더 파일

`<stdlib.h>`:
일반 유틸리티 함수가 정의되어 있는 헤더 파일

`<errno.h>`:
오류 번호 매크로가 정의되어 있는 헤더 파일

`<sys/time.h>`:
POSIX 시스템에서 사용하는 시간 관련 구조체와 함수를 정의하는 헤더 파일

## 주요 함수

`pthread_create`:
새로운 스레드를 생성하는 함수.

`pthread_join`:
지정한 스레드가 종료될 때까지 기다리는 함수. 스레드의 반환값도 받을 수 있다.

`pthread_detach`:
스레드 종료 시 해당 스레드의 리소스를 자동으로 해제하도록 설정하는 함수.

`pthread_mutex_init`:
뮤텍스를 초기화하는 함수.

`pthread_mutex_destroy`:
뮤텍스를 제거하는 함수. 뮤텍스를 사용하고 나서는 반드시 제거해야 한다.

`pthread_mutex_lock`:
뮤텍스를 잠그는 함수. 이미 잠겨있다면, 잠금이 해제될 때까지 대기한다.

`pthread_mutex_unlock`:
뮤텍스의 잠금을 해제하는 함수.

`sem_init`:
세마포어를 초기화하는 함수.

`sem_destroy`:
세마포어를 제거하는 함수.

`sem_wait`:
세마포어를 기다리는 함수. 세마포어 값이 0이면, 세마포어가 0 이상이 될 때까지 기다린다.

`sem_post`:
세마포어를 증가시키는 함수.

`gettimeofday`:
현재 시간 정보를 얻기 위한 함수. 시간 정보는 struct timeval 구조체에 저장된다.

스레드와 동기화 메커니즘을 사용하는 프로그래밍은 복잡할 수 있지만, 함수들의 용도와 사용 방법을 잘 이해하면, 동시에 실행되는 작업을 안정적으로 관리할 수 있다.

## 주요 매크로

`PTHREAD_MUTEX_INITIALIZER`: 정적으로 선언된 뮤텍스를 초기화하는 매크로

## 주요 자료형

`pthread_t`:
스레드를 위한 POSIX 스레드 자료형이다. 각 스레드는 이 타입을 가지는 고유한 식별자를 가진다.

`pthread_mutex_t`:
뮤텍스를 위한 POSIX 스레드 자료형이다.

`sem_t`:
세마포어를 위한 POSIX 세마포어 자료형이다.

`struct timeval`:
초와 마이크로초 단위로 시간 정보를 저장하는 구조체로 `tv_sec` 멤버는 초 단위의 시간을 저장하고 `tv_usec` 멤버는 마이크로초 단위의 멤버를 저장한다.
```C
struct timeval
{
    time_t      tv_sec;     // 초 단위의 시간
    suseconds_t tv_usec;    // 마이크로초 단위의 시간
};
```

`time_t`:
시간(초)를 나타내는 타입으로 부호 있는 정수형이며 운영체제마다 다르나 대부분 `signed long` 혹은 `singed long long`으로 정의된다.

`suseconds_t`:
시간(마이크로초)를 나타내는 타입으로 부호 있는 정수형이며 운영체제마다 다르나 대부분 `signed int` 혹은 `signed long`으로 정의된다.


## 주요 함수 프로토타입

```C
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                    void *(*start_routine) (void *), void *arg)
새로운 스레드를 생성한다. start_routine 함수에 arg를 전달하여 시작한다.
```
```C
int pthread_join(pthread_t thread, void **retval)
특정 스레드의 종료를 대기한다. 스레드가 반환하는 값은 retval에 저장된다.
```
```C
int pthread_detach(pthread_t thread)
스레드가 종료할 때, 시스템이 스레드의 리소스를 자동으로 회수하도록 설정한다.
```
```C
int pthread_mutex_init(pthread_mutex_t *restrict mutex,
                        const pthread_mutexattr_t *restrict attr)
뮤텍스를 초기화한다.
```
```C
int pthread_mutex_destroy(pthread_mutex_t *mutex)
뮤텍스를 해제한다.
```
```C
int pthread_mutex_lock(pthread_mutex_t *mutex)
뮤텍스를 잠그고, 만약 이미 잠겨있다면 잠금이 해제될 때까지 기다린다.
```
```C
int pthread_mutex_unlock(pthread_mutex_t *mutex)
뮤텍스 잠금을 해제한다.
```
```C
int sem_init(sem_t *sem, int pshared, unsigned value)
세마포어를 초기화한다.
```
```C
int sem_destroy(sem_t *sem)
세마포어를 해제한다.
```
```C
int sem_wait(sem_t *sem)
세마포어를 감소시키고, 세마포어 값이 0이라면 세마포어 값이 0 이상이 될 때까지 대기한다.
```
```C
int sem_post(sem_t *sem)
세마포어 값을 증가시킨다.
```
```C
int gettimeofday(struct timeval *tv, struct timezone *tz)
1970년 1월 1일 00:00:00UTC로부터 경과한 시간을 tv 구조체에 저장한다.
timezone 구조체는 현재는 사용되지 않는 구조체로 인자값에 보통 NULL을 입력한다.
```

각 함수는 성공 시 0을 반환하며, 실패 시 에러 코드를 반환한다. `gettimeofday`의 경우 실패시 -1을 반환한다.(에러 코드는 `errno` 변수에 저장됨) `errno.h`에 정의된 에러 코드와 비교할 수 있다.

# pthread 사용 예제 (세마포어 생략)


`pthread_create`: 스레드를 생성하고 시작함수를 설정
```C
#include <pthread.h>
#include <stdio.h>

void*   print_hello(void* data)
{
    printf("Hello, World!\n");
    return (NULL);
}

int main()
{
    pthread_t   thread_id;

    if (pthread_create(&thread_id, NULL, print_hello, NULL) != 0)
    {
        printf("Thread creation failed\n");
        return (1);
    }
    pthread_exit(NULL);
}
```

`pthread_join`: 스레드가 종료되기를 기다리고 반환값을 받아올 주소를 넘겨줌
```C
#include <pthread.h>
#include <stdio.h>

void*   print_hello(void* data)
{
    printf("Hello, World!\n");
    return (NULL);
}

int main()
{
    pthread_t   thread_id;

    if (pthread_create(&thread_id, NULL, print_hello, NULL) != 0)
    {
        printf("Thread creation failed\n");
        return (1);
    }

    if (pthread_join(thread_id, NULL) != 0)
    {
        printf("Thread join failed\n");
        return (1);
    }
    return (0);
}
```

`pthread_detach`: 스레드가 종료될 때 자동으로 리소스를 반환하게 함 (join 혹은 detach 중에 선택해서 사용)
```C
#include <pthread.h>
#include <stdio.h>

void*   print_hello(void* data)
{
    printf("Hello, World!\n");
    return (NULL);
}

int main()
{
    pthread_t   thread_id;

    if (pthread_create(&thread_id, NULL, print_hello, NULL) != 0)
    {
        printf("Thread creation failed\n");
        return (1);
    }

    if (pthread_detach(thread_id) != 0)
    {
        printf("Thread detach failed\n");
        return (1);
    }
    pthread_exit(NULL);
}
```
`pthread_mutex_init`와 `pthread_mutex_destroy`: 뮤텍스를 초기화하고 해제
```C
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

int main()
{
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed\n");
        return (1);
    }

    // 사용하는 코드

    if (pthread_mutex_destroy(&lock) != 0)
    {
        printf("Mutex destruction failed\n");
        return (1);
    }
    return (0);
}
```

`pthread_mutex_lock`와 `pthread_mutex_unlock`: 뮤텍스로 임계 구역을 보호(lock이 된 후 unlock 전까지 다른 쓰레드의 접근 금지)
```C
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

void*   do_work(void* data)
{
    pthread_mutex_lock(&lock);
    // 임계 구역
    pthread_mutex_unlock(&lock);
    return (NULL);
}

int main()
{
    pthread_t   thread_id;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed\n");
        return (1);
    }
    if (pthread_create(&thread_id, NULL, do_work, NULL) != 0)
    {
        printf("Thread creation failed\n");
        return (1);
    }
    if (pthread_join(thread_id, NULL) != 0)
    {
        printf("Thread join failed\n");
        return (1);
    }
    if (pthread_mutex_destroy(&lock) != 0)
    {
        printf("Mutex destruction failed\n");
        return (1);
    }
    return (0);
}
```
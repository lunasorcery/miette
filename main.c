#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void registerSignalHandlers();
char const* getSignalStr(int signo);


static int s_signo = 0;
static void signalHandler(int signo) {
	s_signo = signo;
}


int main()
{
	registerSignalHandlers();

	// busy loop ;_;
	while (s_signo == 0) {
		usleep(100000u);
	}

	fprintf(
		stderr,
		"you KILL miette? "
		"you kill her process with the %s?\n"
		"oh! oh! jail for mother! "
		"jail for mother for One Thousand Years!!!!\n",
		getSignalStr(s_signo));

	return s_signo;
}



void registerSignalHandlers()
{
	// Register anything that would normally cause a coredump or termination.

#if defined(SIGHUP)
	signal(SIGHUP, signalHandler);
#endif
#if defined(SIGINT)
	signal(SIGINT, signalHandler);
#endif
#if defined(SIGQUIT)
	signal(SIGQUIT, signalHandler);
#endif
#if defined(SIGILL)
	signal(SIGILL, signalHandler);
#endif
#if defined(SIGTRAP)
	signal(SIGTRAP, signalHandler);
#endif
#if defined(SIGABRT)
	signal(SIGABRT, signalHandler);
#endif
#if defined(SIGIOT)
	signal(SIGIOT, signalHandler);
#endif
#if defined(SIGBUS)
	signal(SIGBUS, signalHandler);
#endif
#if defined(SIGEMT)
	signal(SIGEMT, signalHandler);
#endif
#if defined(SIGFPE)
	signal(SIGFPE, signalHandler);
#endif
#if defined(SIGKILL)
	signal(SIGKILL, signalHandler);
#endif
#if defined(SIGUSR1)
	signal(SIGUSR1, signalHandler);
#endif
#if defined(SIGSEGV)
	signal(SIGSEGV, signalHandler);
#endif
#if defined(SIGUSR2)
	signal(SIGUSR2, signalHandler);
#endif
#if defined(SIGPIPE)
	signal(SIGPIPE, signalHandler);
#endif
#if defined(SIGALRM)
	signal(SIGALRM, signalHandler);
#endif
#if defined(SIGTERM)
	signal(SIGTERM, signalHandler);
#endif
#if defined(SIGSTKFLT)
	signal(SIGSTKFLT, signalHandler);
#endif
//#if defined(SIGCHLD) // should ignore
//	signal(SIGCHLD, signalHandler);
//#endif
//#if defined(SIGCLD) // should ignore
//	signal(SIGCLD, signalHandler);
//#endif
//#if defined(SIGCONT) // continue if stopped, don't terminate
//	signal(SIGCONT, signalHandler);
//#endif
#if defined(SIGSTOP)
	signal(SIGSTOP, signalHandler);
#endif
#if defined(SIGTSTP)
	signal(SIGTSTP, signalHandler);
#endif
#if defined(SIGTTIN)
	signal(SIGTTIN, signalHandler);
#endif
#if defined(SIGTTOU)
	signal(SIGTTOU, signalHandler);
#endif
//#if defined(SIGURG) // should ignore
//	signal(SIGURG, signalHandler);
//#endif
#if defined(SIGXCPU)
	signal(SIGXCPU, signalHandler);
#endif
#if defined(SIGXFSZ)
	signal(SIGXFSZ, signalHandler);
#endif
#if defined(SIGVTALRM)
	signal(SIGVTALRM, signalHandler);
#endif
#if defined(SIGPROF)
	signal(SIGPROF, signalHandler);
#endif
//#if defined(SIGWINCH) // should ignore
//	signal(SIGWINCH, signalHandler);
//#endif
#if defined(SIGIO)
	signal(SIGIO, signalHandler);
#endif
#if defined(SIGPOLL)
	signal(SIGPOLL, signalHandler);
#endif
#if defined(SIGPWR)
	signal(SIGPWR, signalHandler);
#endif
#if defined(SIGINFO)
	signal(SIGINFO, signalHandler);
#endif
#if defined(SIGLOST)
	signal(SIGLOST, signalHandler);
#endif
#if defined(SIGSYS)
	signal(SIGSYS, signalHandler);
#endif
#if defined(SIGUNUSED)
	signal(SIGUNUSED, signalHandler);
#endif
}



char const* getSignalStr(int signo)
{
	// Turn the incoming signal number into a string.
	// I'm aware of strsignal(3),
	// but it returns strings like "Bus Error: 10" (at least on my Mac)
	// and I wanted the all-caps macro names instead.

#define RETURN_STRINGIFIED_IF_MATCHES(signo, signal_macro) \
	if (signo == signal_macro) { return #signal_macro; }

#if defined(SIGHUP)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGHUP)
#endif
#if defined(SIGINT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGINT)
#endif
#if defined(SIGQUIT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGQUIT)
#endif
#if defined(SIGILL)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGILL)
#endif
#if defined(SIGTRAP)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGTRAP)
#endif
#if defined(SIGABRT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGABRT)
#endif
#if defined(SIGIOT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGIOT)
#endif
#if defined(SIGBUS)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGBUS)
#endif
#if defined(SIGEMT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGEMT)
#endif
#if defined(SIGFPE)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGFPE)
#endif
#if defined(SIGKILL)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGKILL)
#endif
#if defined(SIGUSR1)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGUSR1)
#endif
#if defined(SIGSEGV)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGSEGV)
#endif
#if defined(SIGUSR2)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGUSR2)
#endif
#if defined(SIGPIPE)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGPIPE)
#endif
#if defined(SIGALRM)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGALRM)
#endif
#if defined(SIGTERM)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGTERM)
#endif
#if defined(SIGSTKFLT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGSTKFLT)
#endif
#if defined(SIGCHLD)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGCHLD)
#endif
#if defined(SIGCLD)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGCLD)
#endif
#if defined(SIGCONT)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGCONT)
#endif
#if defined(SIGSTOP)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGSTOP)
#endif
#if defined(SIGTSTP)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGTSTP)
#endif
#if defined(SIGTTIN)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGTTIN)
#endif
#if defined(SIGTTOU)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGTTOU)
#endif
#if defined(SIGURG)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGURG)
#endif
#if defined(SIGXCPU)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGXCPU)
#endif
#if defined(SIGXFSZ)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGXFSZ)
#endif
#if defined(SIGVTALRM)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGVTALRM)
#endif
#if defined(SIGPROF)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGPROF)
#endif
#if defined(SIGWINCH)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGWINCH)
#endif
#if defined(SIGIO)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGIO)
#endif
#if defined(SIGPOLL)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGPOLL)
#endif
#if defined(SIGPWR)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGPWR)
#endif
#if defined(SIGINFO)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGINFO)
#endif
#if defined(SIGLOST)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGLOST)
#endif
#if defined(SIGSYS)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGSYS)
#endif
#if defined(SIGUNUSED)
	RETURN_STRINGIFIED_IF_MATCHES(signo, SIGUNUSED)
#endif

#undef RETURN_STRINGIFIED_IF_MATCHES

	// if we still didn't get a match...
	static char buffer[32];
	snprintf(buffer, sizeof(buffer), "SIGNAL %d", signo);
	return buffer;
}

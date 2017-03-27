/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:17:35 by ale-batt          #+#    #+#             */
/*   Updated: 2017/03/25 10:45:15 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

# include "libft.h"
# include "ft_nmap_struct.h"
# include "ft_nmap_debug.h"
# include "ft_nmap_scan.h"

# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/ip.h>
# include <netinet/tcp.h>
# include <netinet/ip_icmp.h>
# include <netinet/if_ether.h>
# include <pcap/pcap.h>
# include <pthread.h>
# include <signal.h>

# define OPEN 1
# define FILTERED 0
# define CLOSE -1

t_env		g_env;

int			ft_nmap(void);
int			parser(char **av);
void		print_port_lst(t_list *port_lst);

void		process_return(t_list *port_lst, char buff[], ssize_t size);

void		set_ip_header(struct ip *iph, struct sockaddr_in *dest);
void		set_tcp_header(struct tcphdr *tcph, enum e_tcp_type flags);
void		set_pseudo_header(t_pseudo_hdr *psh, struct sockaddr_in *dest);
void		set_peer(t_peer *peer, int sock, char *addr);

int			create_socket(void);
void		send_range(int sock, int range[], char *hostip, enum e_tcp_type flags);
void		*recv_ack(void *ptr);
void		*listener(void *ptr);

void		get_local_ip(char *buffer);
char		*hostname_to_ip(const char *hostname);
u_short		csum(u_short *ptr, int nbytes);

enum e_tcp_type			tcp_to_enum(struct tcphdr *tcph);

#endif

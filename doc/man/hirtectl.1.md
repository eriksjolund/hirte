% hirtectl 1

## NAME

hirtectl - Simple command line tool to interact with the public D-Bus API of hirte

## SYNOPSIS

**hirtectl** [*options*] *command*

## DESCRIPTION

A simple command line tool that uses the public D-Bus API provided by `hirte` to manage services on all connected `hirte-agents` and retrieve information from them.

**hirtectl [OPTIONS]**

## OPTIONS

#### **--help**, **-h**

Print usage statement and exit.

## Commands

### **hirtectl** [*start|stop|restart|reload*] [*agent*] [*unit*]

Performs one of the listed lifecycle operations on the given systemd unit for the `hirte-agent`.

### **hirtectl** *list-units* [*agent*]

Fetches information about all systemd units on the hirte-agents. If [hirte-agent] is not specified, all agents are queried.

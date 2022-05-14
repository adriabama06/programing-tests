package es.lobby.cmds;

import es.lobby.Main;
import es.lobby.Util;
import es.lobby.config.Config;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;

public class test implements CommandExecutor {
    // Create local variable
    private Main plugin;

    // Connect to main
    public test(Main plugin) {
        this.plugin = plugin;
        // Register the command
        plugin.getCommand("test").setExecutor(this);
    }

    @Override
    public boolean onCommand(CommandSender sender, Command cmd, String label, String[] args) {
        if(!(sender instanceof Player)) {
            sender.sendMessage("Not able for console");
            return true;
        }

        Player p = (Player) sender;
        if(p.hasPermission("lobby.cmd.test")) {
            p.sendMessage("You have permission * or lobby.cmd.test to use this command, good");
            p.sendMessage(Config.GetConfig().getString("version"));
            p.sendMessage(Util.color(Config.GetMessages().get("join").toString().replace("%player%", p.getDisplayName())));
            if(args.length >= 0) {
                if(args[0].equals("reload")) {
                    Config.ReloadConfig(plugin);
                    Config.ReloadMessages(plugin);
                    Config.ReloadLocations(plugin);
                    p.sendMessage("Reloaded!");
                }
            }
            return false;
        } else {
            p.sendMessage("You need lobby.cmd.test to use this command");
        }

        return false; // return false = on command end at the console show how use defined in plugin.yml
    }
}

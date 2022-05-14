package es.protector.cmds;

import es.protector.Main;
import es.protector.Util;
import es.protector.config.Config;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;

import java.util.List;

public class protector implements CommandExecutor {
    // Create local variable
    private Main plugin;

    // Connect to main
    public protector(Main plugin) {
        this.plugin = plugin;
        // Register the command
        plugin.getCommand("protector").setExecutor(this);
    }

    @Override
    public boolean onCommand(CommandSender sender, Command cmd, String label, String[] args) {
        if(sender instanceof Player) {
            if(!((Player) sender).getPlayer().hasPermission("protector.cmd.protector")) {
                return true;
            }
        }

        /*
        Player p = (Player) sender;
        ((Player) sender).getPlayer();
        */
        if(args.length >= 1) {
            if(args[0].equalsIgnoreCase("setarea")) {
                if(args.length == 9 && !(args.length >= 10)) {
                    double x1 = Double.valueOf(args[1]);
                    double y1 = Double.valueOf(args[2]);
                    double z1 = Double.valueOf(args[3]);

                    double x2 = Double.valueOf(args[4]);
                    double y2 = Double.valueOf(args[5]);
                    double z2 = Double.valueOf(args[6]);

                    String areaname = args[7];
                    String world = args[8];

                    List<String> enabledlocations = Config.GetProtect().getStringList("enabledlocations");

                    enabledlocations.add(areaname);

                    Config.GetProtect().set("enabledlocations", enabledlocations);

                    Config.GetProtect().set("locations."+ areaname +".antibuild", true);
                    Config.GetProtect().set("locations."+ areaname +".antidamage", true);
                    Config.GetProtect().set("locations."+ areaname +".antifood", true);

                    Config.GetProtect().set("locations."+ areaname +".x1", x1);
                    Config.GetProtect().set("locations."+ areaname +".y1", y1);
                    Config.GetProtect().set("locations."+ areaname +".z1", z1);

                    Config.GetProtect().set("locations."+ areaname +".x2", x2);
                    Config.GetProtect().set("locations."+ areaname +".y2", y2);
                    Config.GetProtect().set("locations."+ areaname +".z2", z2);
                    Config.GetProtect().set("locations."+ areaname +".world", world);

                    Config.SaveProtect(plugin);

                    sender.sendMessage(Util.color(Config.GetMessages().getString("protector.areaset").replace("%1%", args[1] + " " + args[2] + " " + args[3]).replace("%2%", args[4] + " " +  args[5] + " " +  args[6])));
                } else {
                    sender.sendMessage(Util.color(Config.GetMessages().getString("faltan-args").replace("%args%", "[x y z] [x y z] (areaname sin espaciaos) [mundo]")));
                }
                return true;
            }
            if(args[0].equalsIgnoreCase("reload")) {
                Config.ReloadProtect(plugin);
                Config.ReloadConfig(plugin);
                Config.ReloadMessages(plugin);
                sender.sendMessage(Util.color("&e&l[Protector] &a&lPlugin recargado!"));
                return true;
            }
        } else {
            List<String> help = Config.GetMessages().getStringList("help");
            for(String h : help) {
                sender.sendMessage(Util.color(h));
            }
            return true;
        }
        return true; // return false = on command end at the console show how use defined in plugin.yml
    }
}
